#include "OMPythonSessionManager.h"
#include <QDebug>
#include <QStandardPaths>
#include <QDir>
#include <QCoreApplication>

OMPythonSessionManager* OMPythonSessionManager::instance = nullptr;

OMPythonSessionManager* OMPythonSessionManager::getInstance()
{
    if (!instance) {
        instance = new OMPythonSessionManager();
    }
    return instance;
}

OMPythonSessionManager::OMPythonSessionManager(QObject *parent)
    : QObject(parent), pythonProcess(nullptr), sessionInitialized(false)
{
    // 查找omc路径
    omcPath = QCoreApplication::applicationDirPath() + "/omc";
    if (!QFile::exists(omcPath)) {
        omcPath = "/usr/bin/omc"; // 系统路径
    }
    
    initializeSession();
}

OMPythonSessionManager::~OMPythonSessionManager()
{
    cleanup();
}

void OMPythonSessionManager::initializeSession()
{
    QMutexLocker locker(&sessionMutex);
    
    if (pythonProcess) {
        pythonProcess->kill();
        pythonProcess->deleteLater();
    }
    
    pythonProcess = new QProcess(this);
    connect(pythonProcess, QOverload<int, QProcess::ExitStatus>::of(&QProcess::finished),
            this, &OMPythonSessionManager::onProcessFinished);
    connect(pythonProcess, &QProcess::errorOccurred,
            this, &OMPythonSessionManager::onProcessError);
    
    // Python脚本内容 - 只初始化一次OMPython和OMCSessionZMQ
    QString pythonScript = QString(
        "import sys\n"
        "import os\n"
        "try:\n"
        "    from OMPython import OMCSessionZMQ\n"
        "    # 创建持久化的OMC会话\n"
        "    omc = OMCSessionZMQ()\n"
        "    print('SESSION_READY')\n"
        "    sys.stdout.flush()\n"
        "    \n"
        "    # 命令处理循环\n"
        "    while True:\n"
        "        try:\n"
        "            line = input()\n"
        "            if line.strip() == 'EXIT':\n"
        "                break\n"
        "            elif line.startswith('CMD:'):\n"
        "                cmd = line[4:]\n"
        "                try:\n"
        "                    result = eval('omc.' + cmd)\n"
        "                    print('RESULT:' + str(result))\n"
        "                except Exception as e:\n"
        "                    print('ERROR:' + str(e))\n"
        "                sys.stdout.flush()\n"
        "        except EOFError:\n"
        "            break\n"
        "        except Exception as e:\n"
        "            print('ERROR:' + str(e))\n"
        "            sys.stdout.flush()\n"
        "except ImportError as e:\n"
        "    print('IMPORT_ERROR:' + str(e))\n"
        "except Exception as e:\n"
        "    print('INIT_ERROR:' + str(e))\n"
    );
    
    // 启动Python进程
    pythonProcess->start("python3", QStringList() << "-c" << pythonScript);
    
    sessionInitialized = waitForSessionReady();
    
    if (!sessionInitialized) {
        qDebug() << "Failed to initialize OMPython session";
    }
}

bool OMPythonSessionManager::waitForSessionReady(int timeoutMs)
{
    if (!pythonProcess) return false;
    
    QElapsedTimer timer;
    timer.start();
    
    while (timer.elapsed() < timeoutMs) {
        if (pythonProcess->waitForReadyRead(100)) {
            QString output = QString::fromUtf8(pythonProcess->readAllStandardOutput());
            if (output.contains("SESSION_READY")) {
                return true;
            }
            if (output.contains("ERROR:") || output.contains("IMPORT_ERROR:")) {
                qDebug() << "OMPython initialization error:" << output;
                return false;
            }
        }
        QCoreApplication::processEvents();
    }
    
    return false;
}

QString OMPythonSessionManager::executeCommand(const QString& command, int timeoutMs)
{
    QMutexLocker locker(&sessionMutex);
    
    if (!isSessionReady()) {
        qDebug() << "Session not ready, reinitializing...";
        initializeSession();
        if (!isSessionReady()) {
            return "ERROR: OMPython session not available";
        }
    }
    
    // 发送命令
    QString fullCommand = QString("CMD:%1\n").arg(command);
    pythonProcess->write(fullCommand.toUtf8());
    
    // 等待响应
    if (pythonProcess->waitForReadyRead(timeoutMs)) {
        QString output = QString::fromUtf8(pythonProcess->readAllStandardOutput());
        
        QStringList lines = output.split('\n');
        for (const QString& line : lines) {
            if (line.startsWith("RESULT:")) {
                return line.mid(7); // 移除"RESULT:"前缀
            }
            if (line.startsWith("ERROR:")) {
                return line; // 保留错误前缀
            }
        }
    }
    
    return "ERROR: Command timeout or no response";
}

bool OMPythonSessionManager::isSessionReady()
{
    return pythonProcess && 
           pythonProcess->state() == QProcess::Running && 
           sessionInitialized;
}

void OMPythonSessionManager::resetSession()
{
    initializeSession();
}

void OMPythonSessionManager::cleanup()
{
    QMutexLocker locker(&sessionMutex);
    
    if (pythonProcess) {
        pythonProcess->write("EXIT\n");
        if (!pythonProcess->waitForFinished(3000)) {
            pythonProcess->kill();
        }
        pythonProcess->deleteLater();
        pythonProcess = nullptr;
    }
    
    sessionInitialized = false;
}

void OMPythonSessionManager::onProcessFinished(int exitCode, QProcess::ExitStatus exitStatus)
{
    qDebug() << "OMPython process finished with code:" << exitCode;
    sessionInitialized = false;
}

void OMPythonSessionManager::onProcessError(QProcess::ProcessError error)
{
    qDebug() << "OMPython process error:" << error;
    sessionInitialized = false;
}
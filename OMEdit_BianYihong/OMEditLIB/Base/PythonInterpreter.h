#ifndef PYTHONINTERPRETER_H
#define PYTHONINTERPRETER_H

#include <QObject>
#include <QProcess>
#include <QMutex>
#include <QString>
#include <QTimer>

class PythonInterpreter : public QObject
{
    Q_OBJECT

public:
    static PythonInterpreter* getInstance();
    
    // 执行OMPython命令
    QString executeCommand(const QString& command, int timeoutMs = 5000);
    
    // 检查会话状态
    bool isSessionReady();
    
    // 重置会话
    void resetSession();
    
    // 清理资源
    void cleanup();

private slots:
    void onProcessFinished(int exitCode, QProcess::ExitStatus exitStatus);
    void onProcessError(QProcess::ProcessError error);

private:
    PythonInterpreter(QObject *parent = nullptr);
    ~PythonInterpreter();
    
    void initializeSession();
    bool waitForSessionReady(int timeoutMs = 10000);
    
    static PythonInterpreter* instance;
    QProcess* pythonProcess;
    QMutex sessionMutex;
    bool sessionInitialized;
    QString omcPath;
};

#endif // PYTHONINTERPRETER_H
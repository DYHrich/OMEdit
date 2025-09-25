#ifndef OMPYTHONSESSIONMANAGER_H
#define OMPYTHONSESSIONMANAGER_H

#include <QObject>
#include <QProcess>
#include <QMutex>
#include <QString>
#include <QTimer>

class OMPythonSessionManager : public QObject
{
    Q_OBJECT

public:
    static OMPythonSessionManager* getInstance();
    
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
    OMPythonSessionManager(QObject *parent = nullptr);
    ~OMPythonSessionManager();
    
    void initializeSession();
    bool waitForSessionReady(int timeoutMs = 10000);
    
    static OMPythonSessionManager* instance;
    QProcess* pythonProcess;
    QMutex sessionMutex;
    bool sessionInitialized;
    QString omcPath;
};

#endif // OMPYTHONSESSIONMANAGER_H
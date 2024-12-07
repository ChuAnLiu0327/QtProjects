#ifndef SENDFILE_H
#define SENDFILE_H

#include <QObject>
#include <QTcpSocket>

class SendFile : public QObject
{
    Q_OBJECT
public:
    explicit SendFile(QObject *parent = nullptr);

    // 连接服务器‘
    void ConnectServer(unsigned short port,QString IP);

    // 发送文件
    void SendFileFunction(QString FilePath);

signals:
    void connectOK();
    void gameover();
    void sendPercent(int num);
private:
    QTcpSocket *m_tcp;
};

#endif // SENDFILE_H

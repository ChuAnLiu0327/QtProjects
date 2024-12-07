#include "sendfile.h"
#include <QFile>
#include <QFileInfo>
#include <QJsonObject>
#include <QJsonDocument>

SendFile::SendFile(QObject *parent)
    : QObject{parent}
{}

void SendFile::ConnectServer(unsigned short port, QString ip)
{
    m_tcp = new QTcpSocket;
    m_tcp->connectToHost(QHostAddress(ip),port);

    connect(m_tcp,&QTcpSocket::connected,this,&SendFile::connectOK);
    connect(m_tcp,&QTcpSocket::disconnected,this,[=]()
            {
        m_tcp->close();
       //m_tcp->deleteLater();
        emit gameover();
    });
}

void SendFile::SendFileFunction(QString FilePath)
{
    QFile file(FilePath);
    QFileInfo info(FilePath);

    int fileSize = info.size();
    QString fileExtension = info.suffix();
    // 创建JSON数据用于发送
    QJsonObject jsonObject;
    jsonObject["FileSize"] = fileSize;
    jsonObject["FileFormat"] = fileExtension;
    QJsonDocument jsonDoc(jsonObject);
    QByteArray jsonData = jsonDoc.toJson();

    m_tcp->write(jsonData,100);

    file.open(QFile::ReadOnly);

    while(!file.atEnd())
    {
        static int num = 0;
        // 再读取剩下的文件用于发送
        QByteArray line = file.readLine();
        num += line.size();
        int percent = (num*100/fileSize);
        m_tcp->write(line);// TCP发送数据
        //qDebug() << line;
        emit sendPercent(percent); // 信号槽发送百分比数据
        if(percent==100)
        {
           file.close();
        }
    }
}

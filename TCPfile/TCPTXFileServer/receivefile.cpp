#include "receivefile.h"
#include <QFile>
#include <QJsonObject>
#include <QJsonDocument>

QString filepath;

receivefile::receivefile(QTcpSocket *tcp,QObject *parent)
    : QThread{parent}
{
    m_tcp = tcp;
    QString path;
}

void receivefile::run()
{
    static int count = 0;
    static int total = 0;

    connect(m_tcp,&QTcpSocket::readyRead,this,[=]()
    {
        if(count == 0)
        {
            QByteArray buffer = m_tcp->read(100);
        // 解析json数据
            int endIndex = buffer.lastIndexOf('}');
            QByteArray jsonData = buffer.left(endIndex + 1);
            QJsonDocument jsonDoc = QJsonDocument::fromJson(jsonData);
            QJsonObject jsonObject = jsonDoc.object();
            QString FileFormat = jsonObject["FileFormat"].toString();
            int FileSize = jsonObject["FileSize"].toInt();
            qDebug() << FileFormat;
            qDebug() << FileSize;
            total = FileSize;
            filepath = "receive."+FileFormat;
        }
    });
    QFile *file = new QFile(filepath);
    file->open(QFile::WriteOnly);

    //接收数据
    connect(m_tcp,&QTcpSocket::readyRead,this,[=]()
    {
        //读出剩余的数据
        QByteArray all = m_tcp->readAll();
        count+=all.size();
        //qDebug() << all;
        file->write(all);
        if(count==total)
        {
            //m_tcp->close();
            //m_tcp->deleteLater();
            file->close();
            file->deleteLater();
            count = 0;
            total = 0;
            emit over();
        }

   });
    // 进入事件循环
    exec();
}

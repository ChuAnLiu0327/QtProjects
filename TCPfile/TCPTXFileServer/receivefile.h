#ifndef RECEIVEFILE_H
#define RECEIVEFILE_H

#include <QThread>
#include <QTcpSocket>

class receivefile : public QThread
{
    Q_OBJECT
public:
    explicit receivefile(QTcpSocket *tcp,QObject *parent = nullptr);

protected:
    void run() override;

private:
    QTcpSocket *m_tcp;
signals:
    void over();
};

#endif // RECEIVEFILE_H

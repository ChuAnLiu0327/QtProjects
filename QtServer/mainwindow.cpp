#include "mainwindow.h"
#include "ui_mainwindow.h"


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    ui->lineEditPort->setText("8800");
    ui->lineEditIP->setText("127.0.0.1");

    TCP_Server = new QTcpServer(this);

    connect(TCP_Server,&QTcpServer::newConnection,this,[=]()
            {
        TCP_Socket = TCP_Server->nextPendingConnection();
        connect(TCP_Socket,&QTcpSocket::readyRead,this,[=]()
                {
            QByteArray data = TCP_Socket->readAll();
            ui->textBrowserReceiveMessage->append("客户端数据:"+data);
        });
    });

    ui->pushButtonStartServer->setEnabled(true);
    ui->pushButtonCloseServer->setEnabled(false);
    ui->pushButtonSendMessage->setEnabled(false);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButtonStartServer_clicked()
{
    unsigned short port = ui->lineEditPort->text().toUShort();
    QString IP = ui->lineEditIP->text();
    TCP_Server->listen(QHostAddress(IP),port);
    ui->pushButtonStartServer->setEnabled(false);
    ui->pushButtonCloseServer->setEnabled(true);
    ui->pushButtonSendMessage->setEnabled(true);
    QMessageBox::information(nullptr,"提示","服务器已开启");

    ui->lineEditIP->setEnabled(false);
    ui->lineEditPort->setEnabled(false);
    ui->textEditSendMessage->setEnabled(true);

}


void MainWindow::on_pushButtonCloseServer_clicked()
{
    TCP_Server->close();
    ui->pushButtonStartServer->setEnabled(true);
    ui->pushButtonCloseServer->setEnabled(false);
    ui->pushButtonSendMessage->setEnabled(false);
    QMessageBox::warning(nullptr,"提示","服务器已关闭");
    ui->lineEditIP->setEnabled(true);
    ui->lineEditPort->setEnabled(true);
    ui->textEditSendMessage->setEnabled(false);
}


void MainWindow::on_pushButtonSendMessage_clicked()
{
    QString SendMessage = ui->textEditSendMessage->toPlainText();
    TCP_Socket->write(SendMessage.toUtf8());
    ui->textBrowserReceiveMessage->append("服务器端:"+SendMessage);
}


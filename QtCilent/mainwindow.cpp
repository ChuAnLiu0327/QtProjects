#include "mainwindow.h"
#include "ui_mainwindow.h"


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    ui->lineEditPort->setText("8800");
    ui->lineEditIP->setText("127.0.0.1");

    TCP_Socket = new QTcpSocket(this);

    connect(TCP_Socket,&QTcpSocket::readyRead,this,[=]()
    {
        QByteArray data = TCP_Socket->readAll();
        ui->textBrowserReceiveMessage->append("服务器端:"+data);
    });

    connect(TCP_Socket,&QTcpSocket::disconnected,this,[=]()
    {
        TCP_Socket->close();
        TCP_Socket->deleteLater();
        Label_Status->setPixmap(QPixmap(":/new/prefix1/images/ConnectFailed.png").scaled(20,20));
        QMessageBox::warning(nullptr,"提示","服务器已断开");

    });

    connect(TCP_Socket,&QTcpSocket::connected,this,[=]()
    {
        Label_Status->setPixmap(QPixmap(":/new/prefix1/images/ConnectSuccessful.png").scaled(20,20));
        ui->pushButtonConnectServer->setEnabled(false);
        ui->pushButtonCloseServer->setEnabled(true);
        ui->pushButtonSendMessage->setEnabled(true);
        QMessageBox::information(nullptr,"提示","服务器已连接");
        ui->lineEditIP->setEnabled(false);
        ui->lineEditPort->setEnabled(false);
        ui->textEditSendMessage->setEnabled(true);
    });

    ui->pushButtonConnectServer->setEnabled(true);
    ui->pushButtonCloseServer->setEnabled(false);
    ui->pushButtonSendMessage->setEnabled(false);
    ui->textEditSendMessage->setEnabled(false);

    Label_Status  = new QLabel;
    Label_Status->setPixmap(QPixmap(":/new/prefix1/images/ConnectFailed.png").scaled(20,20));
    ui->statusbar->addWidget(new QLabel("连接状态"));
    ui->statusbar->addWidget(Label_Status);

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButtonSendMessage_clicked()
{
    QString SendMessage = ui->textEditSendMessage->toPlainText();
    TCP_Socket->write(SendMessage.toUtf8());
    ui->textBrowserReceiveMessage->append("客户端:"+SendMessage);
}

void MainWindow::on_pushButtonConnectServer_clicked()
{
    unsigned short port = ui->lineEditPort->text().toUShort();
    QString IP = ui->lineEditIP->text();
    TCP_Socket->connectToHost(QHostAddress(IP),port);
}


void MainWindow::on_pushButtonCloseServer_clicked()
{
    TCP_Socket->close();
    Label_Status->setPixmap(QPixmap(":/new/prefix1/images/ConnectFailed.png").scaled(20,20));
    QMessageBox::warning(nullptr,"提示","服务器已断开");
    ui->pushButtonConnectServer->setEnabled(true);
    ui->pushButtonCloseServer->setEnabled(false);
    ui->pushButtonSendMessage->setEnabled(false);
}


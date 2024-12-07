#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "receivefile.h"
#include <QFileDialog>
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    ui->pushButtonCloseServer->setEnabled(false);
    ui->lineEditIP->setText("127.0.0.1");
    ui->lineEditPort->setText("9000");

    MyServer = new QTcpServer;

    connect(MyServer,&QTcpServer::newConnection,this,[=]()
    {
        QTcpSocket *tcp = MyServer->nextPendingConnection();
        //子线程
        receivefile *subThread = new receivefile(tcp);
        subThread->start();
        connect(subThread,&receivefile::over,this,[=]()
                {
            //subThread->exit();
            //subThread->wait();
            //subThread->deleteLater();
            QMessageBox::information(this,"文件接收","文件接收完毕");
            ui->textBrowserData->append("文件接收完毕!");
        });
    });
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButtonSetListen_clicked()
{
    unsigned short port = ui->lineEditPort->text().toUShort();
    QString ip = ui->lineEditIP->text();
    MyServer->listen(QHostAddress(ip),port);
    ui->textBrowserData->append("服务器开启成功!");
    QMessageBox::information(this,"提示","服务器开启成功!");
    ui->pushButtonSetListen->setEnabled(false);
    ui->pushButtonCloseServer->setEnabled(true);
}


void MainWindow::on_pushButtonCloseServer_clicked()
{
    MyServer->close();
    QMessageBox::warning(this,"提示","服务器已经关闭！");
    ui->textBrowserData->append("服务器已关闭!");
    ui->pushButtonCloseServer->setEnabled(false);
    ui->pushButtonSetListen->setEnabled(true);
}


void MainWindow::on_pushButton_clicked()
{
    QString dir = QFileDialog::getExistingDirectory(this, "选择文件夹");
    ui->textBrowserData->append("保存的文件夹目录为: "+dir);
    emit SendSaveDirPath(dir);
}


#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "sendfile.h"
#include <QMessageBox>
#include <QFileDialog>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->lineEditIP->setText("127.0.0.1");
    ui->lineEditPort->setText("9000");
    ui->progressBar->setRange(0,100);
    ui->progressBar->setValue(0);

    // 创建线程对象
    QThread *t = new QThread;
    //创建任务对象
    SendFile *worker = new SendFile;

    worker->moveToThread(t);

    connect(this,&MainWindow::startConnect,worker,&SendFile::ConnectServer);

    connect(this,&MainWindow::sendFile,worker,&SendFile::SendFileFunction);

    connect(worker,&SendFile::sendPercent,this,[=](int percent)
    {
        ui->progressBar->setValue(percent);
    });

    //处理主线程发送的信号
    connect(worker,&SendFile::connectOK,this,[=]()
            {
        QMessageBox::information(this,"连接服务器","成功");
    });

    connect(worker,&SendFile::gameover,this,[=]()
            {
        t->quit();
        t->wait();
        worker->deleteLater();
        t->deleteLater();
    });
    //启动线程
    t->start();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButtonConnectServer_clicked()
{
    QString ip = ui->lineEditIP->text();
    unsigned short port = ui->lineEditPort->text().toUShort();
    emit startConnect(port,ip);
}


void MainWindow::on_pushButtonSelectFile_clicked()
{
    QString path = QFileDialog::getOpenFileName();
    if(path.isEmpty())
    {
        QMessageBox::warning(this,"打开文件","选择路径不能为空");
        return;
    }
    ui->lineEditFilePath->setText(path);
}


void MainWindow::on_pushButtonSendFile_clicked()
{
    emit sendFile(ui->lineEditFilePath->text());
}


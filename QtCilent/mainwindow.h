#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QHostAddress>
#include <QMessageBox>
#include <QTcpSocket>
#include <QLabel>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:

    void on_pushButtonConnectServer_clicked();

    void on_pushButtonCloseServer_clicked();

    void on_pushButtonSendMessage_clicked();

private:
    Ui::MainWindow *ui;
    QTcpSocket *TCP_Socket;
    QLabel *Label_Status;
};
#endif // MAINWINDOW_H

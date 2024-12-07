#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTcpServer>


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
    void on_pushButtonSetListen_clicked();

    void on_pushButtonCloseServer_clicked();

    void on_pushButton_clicked();
signals:
    void SendSaveDirPath(QString path);
private:
    Ui::MainWindow *ui;
    QTcpServer *MyServer;
};
#endif // MAINWINDOW_H

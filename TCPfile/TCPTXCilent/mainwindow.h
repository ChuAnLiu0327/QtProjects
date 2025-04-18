#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QThread>

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

signals:
    void startConnect(unsigned short,QString);
    void sendFile(QString path);

private slots:
    void on_pushButtonConnectServer_clicked();

    void on_pushButtonSelectFile_clicked();

    void on_pushButtonSendFile_clicked();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H

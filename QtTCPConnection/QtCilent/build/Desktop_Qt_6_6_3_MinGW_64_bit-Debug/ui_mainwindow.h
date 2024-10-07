/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.6.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QVBoxLayout *verticalLayout_4;
    QVBoxLayout *verticalLayout;
    QWidget *widget;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QLineEdit *lineEditPort;
    QPushButton *pushButtonConnectServer;
    QWidget *widget_2;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_2;
    QLineEdit *lineEditIP;
    QPushButton *pushButtonCloseServer;
    QGroupBox *groupBox;
    QVBoxLayout *verticalLayout_2;
    QTextBrowser *textBrowserReceiveMessage;
    QGroupBox *groupBox_2;
    QVBoxLayout *verticalLayout_3;
    QTextEdit *textEditSendMessage;
    QWidget *widget_3;
    QHBoxLayout *horizontalLayout_3;
    QSpacerItem *horizontalSpacer;
    QPushButton *pushButtonSendMessage;
    QSpacerItem *horizontalSpacer_2;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(797, 718);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/new/prefix1/images/cilent.png"), QSize(), QIcon::Normal, QIcon::Off);
        MainWindow->setWindowIcon(icon);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        verticalLayout_4 = new QVBoxLayout(centralwidget);
        verticalLayout_4->setObjectName("verticalLayout_4");
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName("verticalLayout");
        widget = new QWidget(centralwidget);
        widget->setObjectName("widget");
        horizontalLayout = new QHBoxLayout(widget);
        horizontalLayout->setObjectName("horizontalLayout");
        label = new QLabel(widget);
        label->setObjectName("label");

        horizontalLayout->addWidget(label);

        lineEditPort = new QLineEdit(widget);
        lineEditPort->setObjectName("lineEditPort");

        horizontalLayout->addWidget(lineEditPort);

        pushButtonConnectServer = new QPushButton(widget);
        pushButtonConnectServer->setObjectName("pushButtonConnectServer");

        horizontalLayout->addWidget(pushButtonConnectServer);


        verticalLayout->addWidget(widget);

        widget_2 = new QWidget(centralwidget);
        widget_2->setObjectName("widget_2");
        horizontalLayout_2 = new QHBoxLayout(widget_2);
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        label_2 = new QLabel(widget_2);
        label_2->setObjectName("label_2");

        horizontalLayout_2->addWidget(label_2);

        lineEditIP = new QLineEdit(widget_2);
        lineEditIP->setObjectName("lineEditIP");

        horizontalLayout_2->addWidget(lineEditIP);

        pushButtonCloseServer = new QPushButton(widget_2);
        pushButtonCloseServer->setObjectName("pushButtonCloseServer");

        horizontalLayout_2->addWidget(pushButtonCloseServer);


        verticalLayout->addWidget(widget_2);


        verticalLayout_4->addLayout(verticalLayout);

        groupBox = new QGroupBox(centralwidget);
        groupBox->setObjectName("groupBox");
        verticalLayout_2 = new QVBoxLayout(groupBox);
        verticalLayout_2->setObjectName("verticalLayout_2");
        textBrowserReceiveMessage = new QTextBrowser(groupBox);
        textBrowserReceiveMessage->setObjectName("textBrowserReceiveMessage");

        verticalLayout_2->addWidget(textBrowserReceiveMessage);


        verticalLayout_4->addWidget(groupBox);

        groupBox_2 = new QGroupBox(centralwidget);
        groupBox_2->setObjectName("groupBox_2");
        verticalLayout_3 = new QVBoxLayout(groupBox_2);
        verticalLayout_3->setObjectName("verticalLayout_3");
        textEditSendMessage = new QTextEdit(groupBox_2);
        textEditSendMessage->setObjectName("textEditSendMessage");

        verticalLayout_3->addWidget(textEditSendMessage);


        verticalLayout_4->addWidget(groupBox_2);

        widget_3 = new QWidget(centralwidget);
        widget_3->setObjectName("widget_3");
        horizontalLayout_3 = new QHBoxLayout(widget_3);
        horizontalLayout_3->setObjectName("horizontalLayout_3");
        horizontalSpacer = new QSpacerItem(224, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer);

        pushButtonSendMessage = new QPushButton(widget_3);
        pushButtonSendMessage->setObjectName("pushButtonSendMessage");

        horizontalLayout_3->addWidget(pushButtonSendMessage);

        horizontalSpacer_2 = new QSpacerItem(224, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_2);


        verticalLayout_4->addWidget(widget_3);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 797, 25));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "TCP\345\256\242\346\210\267\347\253\257", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "\347\253\257\345\217\243\357\274\232", nullptr));
        pushButtonConnectServer->setText(QCoreApplication::translate("MainWindow", "\350\277\236\346\216\245\346\234\215\345\212\241\345\231\250", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "IP\357\274\232", nullptr));
        pushButtonCloseServer->setText(QCoreApplication::translate("MainWindow", "\346\226\255\345\274\200\346\234\215\345\212\241\345\231\250", nullptr));
        groupBox->setTitle(QCoreApplication::translate("MainWindow", "\346\216\245\346\224\266\346\266\210\346\201\257\357\274\232", nullptr));
        groupBox_2->setTitle(QCoreApplication::translate("MainWindow", "\345\217\221\351\200\201\346\266\210\346\201\257:", nullptr));
        pushButtonSendMessage->setText(QCoreApplication::translate("MainWindow", "\345\217\221\351\200\201", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H

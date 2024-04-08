/********************************************************************************
** Form generated from reading UI file 'welcomewindow.ui'
**
** Created by: Qt User Interface Compiler version 6.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WELCOMEWINDOW_H
#define UI_WELCOMEWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_WelcomeWindow
{
public:
    QWidget *centralwidget;
    QLabel *label_1;
    QPushButton *pushButton_2;
    QPushButton *pushButton;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *WelcomeWindow)
    {
        if (WelcomeWindow->objectName().isEmpty())
            WelcomeWindow->setObjectName("WelcomeWindow");
        WelcomeWindow->resize(415, 160);
        centralwidget = new QWidget(WelcomeWindow);
        centralwidget->setObjectName("centralwidget");
        label_1 = new QLabel(centralwidget);
        label_1->setObjectName("label_1");
        label_1->setGeometry(QRect(90, 20, 241, 41));
        QFont font;
        font.setPointSize(20);
        label_1->setFont(font);
        pushButton_2 = new QPushButton(centralwidget);
        pushButton_2->setObjectName("pushButton_2");
        pushButton_2->setGeometry(QRect(220, 80, 181, 25));
        pushButton = new QPushButton(centralwidget);
        pushButton->setObjectName("pushButton");
        pushButton->setGeometry(QRect(20, 80, 181, 25));
        WelcomeWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(WelcomeWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 415, 21));
        WelcomeWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(WelcomeWindow);
        statusbar->setObjectName("statusbar");
        WelcomeWindow->setStatusBar(statusbar);

        retranslateUi(WelcomeWindow);

        QMetaObject::connectSlotsByName(WelcomeWindow);
    } // setupUi

    void retranslateUi(QMainWindow *WelcomeWindow)
    {
        WelcomeWindow->setWindowTitle(QCoreApplication::translate("WelcomeWindow", "MainWindow", nullptr));
        label_1->setText(QCoreApplication::translate("WelcomeWindow", "Database Visualiser", nullptr));
        pushButton_2->setText(QCoreApplication::translate("WelcomeWindow", "Sign in", nullptr));
        pushButton->setText(QCoreApplication::translate("WelcomeWindow", "Log in", nullptr));
    } // retranslateUi

};

namespace Ui {
    class WelcomeWindow: public Ui_WelcomeWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WELCOMEWINDOW_H

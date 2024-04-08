/********************************************************************************
** Form generated from reading UI file 'interfacewindow.ui'
**
** Created by: Qt User Interface Compiler version 6.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_INTERFACEWINDOW_H
#define UI_INTERFACEWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTableView>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_InterfaceWindow
{
public:
    QWidget *centralwidget;
    QPushButton *DeleteDatabaseButton;
    QTableView *DatabaseView;
    QLabel *label_2;
    QPushButton *UsersButton;
    QLineEdit *lineEdit_2;
    QPushButton *AddDatabaseButton;
    QLabel *label_3;
    QPushButton *SelectDatabaseButton;
    QPushButton *RightsButton;
    QPushButton *AddProfileButton;
    QPushButton *DeleteProfileButton;
    QPushButton *ValidateSQLButton;
    QComboBox *ProfilesBox;
    QLabel *label;
    QPushButton *LogOutButton;
    QComboBox *DatabasesBox;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *InterfaceWindow)
    {
        if (InterfaceWindow->objectName().isEmpty())
            InterfaceWindow->setObjectName("InterfaceWindow");
        InterfaceWindow->resize(395, 372);
        centralwidget = new QWidget(InterfaceWindow);
        centralwidget->setObjectName("centralwidget");
        DeleteDatabaseButton = new QPushButton(centralwidget);
        DeleteDatabaseButton->setObjectName("DeleteDatabaseButton");
        DeleteDatabaseButton->setGeometry(QRect(10, 250, 111, 25));
        DatabaseView = new QTableView(centralwidget);
        DatabaseView->setObjectName("DatabaseView");
        DatabaseView->setGeometry(QRect(130, 50, 256, 241));
        label_2 = new QLabel(centralwidget);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(10, 130, 67, 17));
        UsersButton = new QPushButton(centralwidget);
        UsersButton->setObjectName("UsersButton");
        UsersButton->setGeometry(QRect(200, 10, 101, 31));
        UsersButton->setFocusPolicy(Qt::StrongFocus);
        lineEdit_2 = new QLineEdit(centralwidget);
        lineEdit_2->setObjectName("lineEdit_2");
        lineEdit_2->setGeometry(QRect(12, 300, 321, 25));
        AddDatabaseButton = new QPushButton(centralwidget);
        AddDatabaseButton->setObjectName("AddDatabaseButton");
        AddDatabaseButton->setGeometry(QRect(10, 190, 111, 25));
        label_3 = new QLabel(centralwidget);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(12, 280, 101, 17));
        SelectDatabaseButton = new QPushButton(centralwidget);
        SelectDatabaseButton->setObjectName("SelectDatabaseButton");
        SelectDatabaseButton->setGeometry(QRect(10, 220, 111, 25));
        RightsButton = new QPushButton(centralwidget);
        RightsButton->setObjectName("RightsButton");
        RightsButton->setGeometry(QRect(140, 10, 61, 31));
        AddProfileButton = new QPushButton(centralwidget);
        AddProfileButton->setObjectName("AddProfileButton");
        AddProfileButton->setGeometry(QRect(10, 70, 111, 25));
        DeleteProfileButton = new QPushButton(centralwidget);
        DeleteProfileButton->setObjectName("DeleteProfileButton");
        DeleteProfileButton->setGeometry(QRect(10, 100, 111, 25));
        ValidateSQLButton = new QPushButton(centralwidget);
        ValidateSQLButton->setObjectName("ValidateSQLButton");
        ValidateSQLButton->setGeometry(QRect(340, 300, 41, 25));
        ProfilesBox = new QComboBox(centralwidget);
        ProfilesBox->addItem(QString());
        ProfilesBox->setObjectName("ProfilesBox");
        ProfilesBox->setGeometry(QRect(10, 10, 131, 31));
        label = new QLabel(centralwidget);
        label->setObjectName("label");
        label->setGeometry(QRect(10, 50, 67, 17));
        LogOutButton = new QPushButton(centralwidget);
        LogOutButton->setObjectName("LogOutButton");
        LogOutButton->setGeometry(QRect(300, 10, 81, 31));
        DatabasesBox = new QComboBox(centralwidget);
        DatabasesBox->addItem(QString());
        DatabasesBox->setObjectName("DatabasesBox");
        DatabasesBox->setGeometry(QRect(10, 150, 111, 31));
        InterfaceWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(InterfaceWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 395, 21));
        InterfaceWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(InterfaceWindow);
        statusbar->setObjectName("statusbar");
        InterfaceWindow->setStatusBar(statusbar);

        retranslateUi(InterfaceWindow);

        QMetaObject::connectSlotsByName(InterfaceWindow);
    } // setupUi

    void retranslateUi(QMainWindow *InterfaceWindow)
    {
        InterfaceWindow->setWindowTitle(QCoreApplication::translate("InterfaceWindow", "MainWindow", nullptr));
        DeleteDatabaseButton->setText(QCoreApplication::translate("InterfaceWindow", "Delete", nullptr));
        label_2->setText(QCoreApplication::translate("InterfaceWindow", "Database :", nullptr));
        UsersButton->setText(QCoreApplication::translate("InterfaceWindow", "Users", nullptr));
        lineEdit_2->setText(QString());
        AddDatabaseButton->setText(QCoreApplication::translate("InterfaceWindow", "Add", nullptr));
        label_3->setText(QCoreApplication::translate("InterfaceWindow", "Requete SQL", nullptr));
        SelectDatabaseButton->setText(QCoreApplication::translate("InterfaceWindow", "Select", nullptr));
        RightsButton->setText(QCoreApplication::translate("InterfaceWindow", "Rights", nullptr));
        AddProfileButton->setText(QCoreApplication::translate("InterfaceWindow", "Add", nullptr));
        DeleteProfileButton->setText(QCoreApplication::translate("InterfaceWindow", "Delete", nullptr));
        ValidateSQLButton->setText(QCoreApplication::translate("InterfaceWindow", "OK", nullptr));
        ProfilesBox->setItemText(0, QString());

        label->setText(QCoreApplication::translate("InterfaceWindow", "Profile :", nullptr));
        LogOutButton->setText(QCoreApplication::translate("InterfaceWindow", "Log out", nullptr));
        DatabasesBox->setItemText(0, QString());

    } // retranslateUi

};

namespace Ui {
    class InterfaceWindow: public Ui_InterfaceWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_INTERFACEWINDOW_H

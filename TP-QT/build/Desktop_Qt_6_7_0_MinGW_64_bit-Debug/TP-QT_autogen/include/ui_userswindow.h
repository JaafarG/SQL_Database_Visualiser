/********************************************************************************
** Form generated from reading UI file 'userswindow.ui'
**
** Created by: Qt User Interface Compiler version 6.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_USERSWINDOW_H
#define UI_USERSWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_UsersWindow
{
public:
    QLabel *label;
    QPushButton *DeleteButton;
    QComboBox *UsersBox;
    QPushButton *BackButton;
    QComboBox *RightsBox;
    QPushButton *SetRightsButton;

    void setupUi(QWidget *UsersWindow)
    {
        if (UsersWindow->objectName().isEmpty())
            UsersWindow->setObjectName("UsersWindow");
        UsersWindow->resize(343, 134);
        label = new QLabel(UsersWindow);
        label->setObjectName("label");
        label->setGeometry(QRect(30, 40, 41, 17));
        QFont font;
        font.setPointSize(11);
        label->setFont(font);
        DeleteButton = new QPushButton(UsersWindow);
        DeleteButton->setObjectName("DeleteButton");
        DeleteButton->setGeometry(QRect(10, 80, 91, 21));
        UsersBox = new QComboBox(UsersWindow);
        UsersBox->addItem(QString());
        UsersBox->setObjectName("UsersBox");
        UsersBox->setGeometry(QRect(100, 30, 131, 31));
        BackButton = new QPushButton(UsersWindow);
        BackButton->setObjectName("BackButton");
        BackButton->setGeometry(QRect(120, 80, 91, 21));
        RightsBox = new QComboBox(UsersWindow);
        RightsBox->addItem(QString());
        RightsBox->addItem(QString());
        RightsBox->addItem(QString());
        RightsBox->addItem(QString());
        RightsBox->addItem(QString());
        RightsBox->setObjectName("RightsBox");
        RightsBox->setGeometry(QRect(260, 30, 71, 31));
        SetRightsButton = new QPushButton(UsersWindow);
        SetRightsButton->setObjectName("SetRightsButton");
        SetRightsButton->setGeometry(QRect(240, 80, 91, 21));

        retranslateUi(UsersWindow);

        QMetaObject::connectSlotsByName(UsersWindow);
    } // setupUi

    void retranslateUi(QWidget *UsersWindow)
    {
        UsersWindow->setWindowTitle(QCoreApplication::translate("UsersWindow", "Form", nullptr));
        label->setText(QCoreApplication::translate("UsersWindow", "Users :", nullptr));
        DeleteButton->setText(QCoreApplication::translate("UsersWindow", "Delete", nullptr));
        UsersBox->setItemText(0, QString());

        BackButton->setText(QCoreApplication::translate("UsersWindow", "Back", nullptr));
        RightsBox->setItemText(0, QCoreApplication::translate("UsersWindow", "Admin", nullptr));
        RightsBox->setItemText(1, QCoreApplication::translate("UsersWindow", "1", nullptr));
        RightsBox->setItemText(2, QCoreApplication::translate("UsersWindow", "2", nullptr));
        RightsBox->setItemText(3, QCoreApplication::translate("UsersWindow", "3", nullptr));
        RightsBox->setItemText(4, QCoreApplication::translate("UsersWindow", "4", nullptr));

        SetRightsButton->setText(QCoreApplication::translate("UsersWindow", "Set Right", nullptr));
    } // retranslateUi

};

namespace Ui {
    class UsersWindow: public Ui_UsersWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_USERSWINDOW_H

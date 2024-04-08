#include "userswindow.h"
#include "ui_userswindow.h"
#include "userdatabase.h"
#include <QMessageBox>

UsersWindow::UsersWindow(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::UsersWindow)
{
    ui->setupUi(this);
    connect(ui->DeleteButton, &QPushButton::clicked, this, &UsersWindow::onDeleteButtonClicked);
    connect(ui->SetRightsButton, &QPushButton::clicked, this, &UsersWindow::onSetButtonClicked);

    populateUsers();
}

UsersWindow::~UsersWindow()
{
    delete ui;
}

void UsersWindow::populateUsers() {
    UserDatabase db("userdatabase.json");
    QJsonObject allUsers = db.getAllUsers(); // You need to implement this method in UserDatabase
    ui->UsersBox->clear(); // Clear the box before populating

    for (const QString &username : allUsers.keys()) {
        ui->UsersBox->addItem(username);
    }
}

void UsersWindow::onDeleteButtonClicked() {
    QString username = ui->UsersBox->currentText();
    if (username.isEmpty()) return;

    UserDatabase db("userdatabase.json");
    if (db.deleteUser(username)) {
        QMessageBox::information(this, tr("User Deleted"), tr("%1 has been deleted.").arg(username));
        populateUsers(); // Refresh the users list
    } else {
        QMessageBox::warning(this, tr("Error"), tr("Could not delete the user."));
    }
}

void UsersWindow::onSetButtonClicked() {
    QString username = ui->UsersBox->currentText();
    QString selectedRight = ui->RightsBox->currentText();
    int rights = mapRightsTextToValue(selectedRight);

    if (username.isEmpty()) return;

    UserDatabase db("userdatabase.json");
    if (db.changeUserRights(username, rights)) {
        QMessageBox::information(this, tr("Rights Updated"), tr("%1's rights have been updated.").arg(username));
    } else {
        QMessageBox::warning(this, tr("Error"), tr("Could not update user rights."));
    }
}

int UsersWindow::mapRightsTextToValue(const QString &rightsText) {
    if (rightsText == "Admin") return 2;
    if (rightsText == "1") return 3;
    if (rightsText == "2") return 4;
    if (rightsText == "3") return 5;
    if (rightsText == "4") return 6;
    return -1; // Invalid right
}

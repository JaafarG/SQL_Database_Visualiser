#include "registerwindow.h"
#include "userdatabase.h"
#include "./ui_registerwindow.h"
#include <QMessageBox>

RegisterWindow::RegisterWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::RegisterWindow)
{
    ui->setupUi(this);
    ui->lineEdit_2->setEchoMode(QLineEdit::Password);
    ui->lineEdit_3->setEchoMode(QLineEdit::Password);
    connect(ui->pushButton, &QPushButton::clicked, this, &RegisterWindow::on_createAccountButton_clicked);
    connect(ui->pushButton_2, &QPushButton::clicked, this, &RegisterWindow::on_backButton_clicked);

}

RegisterWindow::~RegisterWindow()
{
    delete ui;
}

void RegisterWindow::on_backButton_clicked() {
    emit backButtonClicked();
}

void RegisterWindow::on_createAccountButton_clicked() {
    QString username = ui->lineEdit->text();
    QString password = ui->lineEdit_2->text();
    QString passwordver = ui->lineEdit_3->text();

    // Check if username has at least 3 characters
    if (username.length() < 3) {
        QMessageBox::warning(this, "Error", "Username must have at least 3 characters.");
        return;
    }

    // Check if passwords match
    if (password != passwordver) {
        QMessageBox::warning(this, "Error", "Passwords do not correspond.");
        return;
    }

    // Check if password has at least 4 characters
    if (password.length() < 4) {
        QMessageBox::warning(this, "Error", "Password must have at least 4 characters.");
        return;
    }


    int rights = 5; // For a normal user

    UserDatabase db("userdatabase.json");

    if (db.createUser(username, password, rights)) {
        QMessageBox::information(this, "Success", "Account created successfully.");
        emit backButtonClicked(); // Go back to welcome window
    } else {
        QMessageBox::warning(this, "Error", "Username already exists.");
    }
}

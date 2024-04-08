#include "loginwindow.h"
#include "ui_loginwindow.h"
#include "userdatabase.h"
#include "sessionmanager.h"
#include <QMessageBox>

LoginWindow::LoginWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::LoginWindow)
{
    ui->setupUi(this);
    ui->lineEdit_2->setEchoMode(QLineEdit::Password);
    connect(ui->pushButton, &QPushButton::clicked, this, &LoginWindow::on_loginButton_clicked);
    connect(ui->pushButton_2, &QPushButton::clicked, this, &LoginWindow::on_backButton_clicked);
}

LoginWindow::~LoginWindow()
{
    delete ui;
}

void LoginWindow::on_backButton_clicked() {
    emit backButtonClicked();
}

void LoginWindow::on_loginButton_clicked() {
    QString username = ui->lineEdit->text();
    QString password = ui->lineEdit_2->text();

    UserDatabase db("userdatabase.json");

    if (db.validateUser(username, password)) {
        QMessageBox::information(this, "Success", "Logged in successfully.");
        QJsonObject userDetails = db.getUserDetails(username);
        SessionManager::instance().loginUser(username, userDetails);

        emit loginButtonClicked();
    } else {
        QMessageBox::warning(this, "Error", "Invalid username or password.");
    }
}

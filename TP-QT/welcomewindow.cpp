#include "welcomewindow.h"
#include "ui_welcomewindow.h"

WelcomeWindow::WelcomeWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::WelcomeWindow) {
    ui->setupUi(this);
    connect(ui->pushButton, &QPushButton::clicked, this, &WelcomeWindow::on_loginButton_clicked);
    connect(ui->pushButton_2, &QPushButton::clicked, this, &WelcomeWindow::on_registerButton_clicked);
}

WelcomeWindow::~WelcomeWindow() {
    delete ui;
}

void WelcomeWindow::on_loginButton_clicked() {
    emit loginButtonClicked();
}

void WelcomeWindow::on_registerButton_clicked() {
    emit registerButtonClicked();
}

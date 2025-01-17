#ifndef LOGINWINDOW_H
#define LOGINWINDOW_H

#include <QMainWindow>

namespace Ui {
class LoginWindow;
}

class LoginWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit LoginWindow(QWidget *parent = nullptr);
    ~LoginWindow();

signals:
    void backButtonClicked();
    void loginButtonClicked();

private slots:
    void on_backButton_clicked();
    void on_loginButton_clicked();

private:
    Ui::LoginWindow *ui;

};

#endif // LOGINWINDOW_H

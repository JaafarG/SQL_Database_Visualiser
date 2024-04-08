#ifndef WELCOMEWINDOW_H
#define WELCOMEWINDOW_H

#include <QMainWindow>

namespace Ui {
class WelcomeWindow;
}

class WelcomeWindow : public QMainWindow {
    Q_OBJECT

public:
    explicit WelcomeWindow(QWidget *parent = nullptr);
    ~WelcomeWindow();

signals:
    void loginButtonClicked();
    void registerButtonClicked();

private slots:
    void on_loginButton_clicked();
    void on_registerButton_clicked();

private:
    Ui::WelcomeWindow *ui;
};

#endif // WELCOMEWINDOW_H

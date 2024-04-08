#ifndef CONTROLLER_H
#define CONTROLLER_H

#include <QObject>
#include "loginwindow.h"
#include "registerwindow.h"
#include "welcomewindow.h"
#include "interfacewindow.h"
#include "userswindow.h"

class Controller : public QObject {
    Q_OBJECT

public:
    Controller();

public slots:
    void showLoginWindow();
    void showRegisterWindow();
    void showWelcomeWindow();
    void showInterfaceWindow();
    void showUsersWindow();

private:
    LoginWindow *loginWindow;
    RegisterWindow *registerWindow;
    WelcomeWindow *welcomeWindow;
    InterfaceWindow *interfaceWindow;
    UsersWindow *usersWindow;

};

#endif // CONTROLLER_H

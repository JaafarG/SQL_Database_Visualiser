#include "controller.h"

Controller::Controller() {
    loginWindow = new LoginWindow();
    registerWindow = new RegisterWindow();
    welcomeWindow = new WelcomeWindow();
    interfaceWindow = new InterfaceWindow();
    usersWindow = new UsersWindow();

    // Connections for WelcomeWindow
    QObject::connect(welcomeWindow, &WelcomeWindow::loginButtonClicked, this, &Controller::showLoginWindow);
    QObject::connect(welcomeWindow, &WelcomeWindow::registerButtonClicked, this, &Controller::showRegisterWindow);

    // Connections for LoginWindow
    QObject::connect(loginWindow, &LoginWindow::backButtonClicked, this, &Controller::showWelcomeWindow);
    QObject::connect(loginWindow, &LoginWindow::loginButtonClicked, this, &Controller::showInterfaceWindow);

    // Connections for RegisterWindow
    QObject::connect(registerWindow, &RegisterWindow::backButtonClicked, this, &Controller::showWelcomeWindow);

    // Connections for InterfaceWindow
    QObject::connect(interfaceWindow, &InterfaceWindow::logoutRequested, this, &Controller::showWelcomeWindow);
    QObject::connect(interfaceWindow, &InterfaceWindow::usersButtonClicked, this, &Controller::showUsersWindow);

    // Initially show the welcome window
    welcomeWindow->show();
}

void Controller::showLoginWindow() {
    welcomeWindow->hide();
    loginWindow->show();
}

void Controller::showRegisterWindow() {
    welcomeWindow->hide();
    registerWindow->show();
}

void Controller::showWelcomeWindow() {
    if (interfaceWindow) interfaceWindow->hide();
    if (loginWindow) loginWindow->hide();
    if (registerWindow) registerWindow->hide();
    welcomeWindow->show();
}

void Controller::showInterfaceWindow() {
    if (loginWindow) loginWindow->hide();
    interfaceWindow->show();
    interfaceWindow->populateProfiles();
    interfaceWindow->updateUserInterface();
}
void Controller::showUsersWindow(){
    usersWindow->show();
    usersWindow->populateUsers();
}

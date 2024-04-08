#ifndef INTERFACEWINDOW_H
#define INTERFACEWINDOW_H

#include <QMainWindow>
#include <QInputDialog>
#include <QMessageBox>

namespace Ui {
class InterfaceWindow;
}

class InterfaceWindow : public QMainWindow {
    Q_OBJECT

public:
    explicit InterfaceWindow(QWidget *parent = nullptr);
    ~InterfaceWindow();
    void updateUserInterface();
    void populateProfiles();

signals:
    void logoutRequested();
    void usersButtonClicked();

public slots:


private:
    Ui::InterfaceWindow *ui;

    void on_AddDatabaseButton_clicked();
    void on_addProfileButton_clicked();
    void on_deleteProfileButton_clicked();
    void on_logOutButton_clicked();
    void on_RightsButton_clicked();
    void on_UsersButton_clicked();
    void on_SelectDatabaseButton_clicked();
};

#endif // INTERFACEWINDOW_H

#ifndef USERSWINDOW_H
#define USERSWINDOW_H

#include <QWidget>

namespace Ui {
class UsersWindow;
}

class UsersWindow : public QWidget
{
    Q_OBJECT

public:
    explicit UsersWindow(QWidget *parent = nullptr);
    ~UsersWindow();
    void populateUsers();

private:
    Ui::UsersWindow *ui;

private slots :
    void onDeleteButtonClicked();
    void onSetButtonClicked();
    int mapRightsTextToValue(const QString &rightsText);


};

#endif // USERSWINDOW_H

#ifndef REGISTERWINDOW_H
#define REGISTERWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui {
class RegisterWindow;
}
QT_END_NAMESPACE

class RegisterWindow : public QMainWindow
{
    Q_OBJECT

public:
    RegisterWindow(QWidget *parent = nullptr);
    ~RegisterWindow();

signals:
    void backButtonClicked();

private slots:
    void on_backButton_clicked();
    void on_createAccountButton_clicked();

private:
    Ui::RegisterWindow *ui;
};
#endif // REGISTERWINDOW_H

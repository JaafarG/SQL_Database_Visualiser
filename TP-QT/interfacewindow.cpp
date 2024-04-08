#include "interfacewindow.h"
#include "ui_interfacewindow.h"
#include "sessionmanager.h"
#include "userdatabase.h"
#include "QJsonArray"
#include <QFileDialog>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlTableModel>

InterfaceWindow::InterfaceWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::InterfaceWindow) {
    ui->setupUi(this);

    connect(ui->LogOutButton, &QPushButton::clicked, this, &InterfaceWindow::on_logOutButton_clicked);
    connect(ui->AddProfileButton, &QPushButton::clicked, this, &InterfaceWindow::on_addProfileButton_clicked);
    connect(ui->DeleteProfileButton, &QPushButton::clicked, this, &InterfaceWindow::on_deleteProfileButton_clicked);
    connect(ui->RightsButton, &QPushButton::clicked, this, &InterfaceWindow::on_RightsButton_clicked);
    connect(ui->UsersButton, &QPushButton::clicked, this, &InterfaceWindow::on_UsersButton_clicked);
    connect(ui->AddDatabaseButton, &QPushButton::clicked, this, &InterfaceWindow::on_AddDatabaseButton_clicked);
    connect(ui->SelectDatabaseButton, &QPushButton::clicked, this, &InterfaceWindow::on_SelectDatabaseButton_clicked);


}

InterfaceWindow::~InterfaceWindow() {
    delete ui;
}

void InterfaceWindow::updateUserInterface() {
    QString currentUsername = SessionManager::instance().getCurrentUsername();
    UserDatabase db("userdatabase.json");
    QJsonObject userDetails = db.getUserDetails(currentUsername);
    int rights = userDetails["rights"].toInt();

    // Set visibility based on rights
    ui->UsersButton->setVisible(rights == 1);
}

void InterfaceWindow::populateProfiles() {

    ui->ProfilesBox->clear();
    // Retrieve the profiles from the session and populate the combo box
    QString currentUsername = SessionManager::instance().getCurrentUsername();

    UserDatabase db("userdatabase.json");

    QJsonObject userDetails = db.getUserDetails(currentUsername);
    QJsonArray profiles = userDetails["profiles"].toArray();
    for (const QJsonValue &profile : profiles) {
        ui->ProfilesBox->addItem(profile.toString());
    }
}

void InterfaceWindow::on_logOutButton_clicked() {
    int ret = QMessageBox::question(this, tr("Confirm Logout"),
                                    tr("Are you sure you want to log out?"),
                                    QMessageBox::Yes | QMessageBox::No);

    if (ret == QMessageBox::Yes) {
        SessionManager::instance().logoutUser();
        emit logoutRequested();
    }
}

void InterfaceWindow::on_addProfileButton_clicked() {
    bool ok;
    QString profileName = QInputDialog::getText(this, tr("Add Profile"),
                                                tr("Profile name:"), QLineEdit::Normal,
                                                "", &ok);
    if (ok && !profileName.isEmpty()) {
        QString currentUsername = SessionManager::instance().getCurrentUsername();

        UserDatabase db("userdatabase.json");
        if (db.addProfile(currentUsername, profileName)) {
            // Update the profiles list in the interface
            ui->ProfilesBox->addItem(profileName);
            QMessageBox::information(this, tr("Add Profile"), tr("Profile added successfully."));
        } else {
            QMessageBox::warning(this, tr("Add Profile"), tr("Could not add profile."));
        }
    }
}

void InterfaceWindow::on_deleteProfileButton_clicked() {
    QString currentUsername = SessionManager::instance().getCurrentUsername();
    QString selectedProfile = ui->ProfilesBox->currentText();

    if (ui->ProfilesBox->count() <= 1) {
        QMessageBox::warning(this, tr("Warning"), tr("You cannot delete the only profile."));
        return;
    }

    int ret = QMessageBox::warning(this, tr("Confirm Delete"),
                                   tr("Are you sure you want to delete this profile?"),
                                   QMessageBox::Yes | QMessageBox::No);

    if (ret == QMessageBox::Yes) {
        UserDatabase db("userdatabase.json");
        if (db.deleteProfile(currentUsername, selectedProfile)) {
            // Remove the profile from the UI
            ui->ProfilesBox->removeItem(ui->ProfilesBox->currentIndex());
            QMessageBox::information(this, tr("Delete Profile"), tr("Profile deleted successfully."));
        } else {
            QMessageBox::warning(this, tr("Delete Profile"), tr("Could not delete profile."));
        }
    }
}

void InterfaceWindow::on_RightsButton_clicked() {
    QString currentUsername = SessionManager::instance().getCurrentUsername();
    UserDatabase db("userdatabase.json");
    QJsonObject userDetails = db.getUserDetails(currentUsername);
    int rights = userDetails["rights"].toInt();

    QString message;
    switch (rights) {
    case 1:
        message = "You have SuperUser rights.";
        break;
    case 2:
        message = "You have Admin rights.";
        break;
    case 3:
        message = "You have level 1 rights.";
        break;
    case 4:
        message = "You have level 2 rights.";
        break;
    case 5:
        message = "You have level 3 rights.";
        break;
    case 6:
        message = "You have level 4 rights.";
        break;
    default:
        message = "Unknown rights level.";
        break;
    }

    QMessageBox::information(this, tr("Rights Information"), message);
}

void InterfaceWindow::on_UsersButton_clicked() {
    emit usersButtonClicked();

}

void InterfaceWindow::on_AddDatabaseButton_clicked() {
    QString fileName = QFileDialog::getOpenFileName(this, tr("Open Database"), QDir::homePath(), tr("SQLite Database Files (*.db *.sqlite)"));
    if (!fileName.isEmpty()) {
        QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE", "MyDB");
        db.setDatabaseName(fileName);
        if (!db.open()) {
            QMessageBox::critical(this, tr("Error"), tr("Could not open the database."));
            return;
        }

        QSqlQuery query("SELECT name FROM sqlite_master WHERE type='table'", db);
        QStringList tables;
        while (query.next()) {
            QString table = query.value(0).toString();
            tables << table;
        }

        ui->DatabasesBox->addItems(tables); // Assuming your combo box is named DatabaseBox
        db.close();
    }
}

void InterfaceWindow::on_SelectDatabaseButton_clicked() {
    QString tableName = ui->DatabasesBox->currentText(); // Assuming your combo box is named DatabaseBox
    if (!tableName.isEmpty()) {
        QSqlDatabase db = QSqlDatabase::database("MyDB"); // Use the connection name you've added
        if (!db.isOpen()) {
            if (!db.open()) {
                QMessageBox::critical(this, tr("Error"), tr("Could not open the database."));
                return;
            }
        }

        QSqlTableModel *model = new QSqlTableModel(this, db);
        model->setTable(tableName);
        model->select();
        ui->DatabaseView->setModel(model); // Assuming your table view is named DatabaseView
    }
}

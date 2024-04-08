#ifndef USERDATABASE_H
#define USERDATABASE_H

#include <QString>
#include <QJsonObject>

class UserDatabase {
public:
    UserDatabase(const QString &filePath);

    bool createUser(const QString &username, const QString &password, int rights);
    bool validateUser(const QString &username, const QString &password);
    bool userExists(const QString &username);
    void loadDatabase();
    void saveDatabase();
    bool changeUserRights(const QString &username, int newRights);
    bool deleteUser(const QString &username);
    bool addProfile(const QString &username, const QString &profileName);
    bool deleteProfile(const QString &username, const QString &profileName);
    QJsonObject getUserDetails(const QString &username);
    QJsonObject getAllUsers();
private:
    QString filePath;
    QJsonObject database;
};

#endif // USERDATABASE_H

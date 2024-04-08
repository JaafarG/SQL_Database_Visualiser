#include "userdatabase.h"
#include <QFile>
#include <QJsonDocument>
#include <QJsonArray>

UserDatabase::UserDatabase(const QString &filePath) : filePath(filePath) {
    loadDatabase();
}

bool UserDatabase::createUser(const QString &username, const QString &password, int rights) {
    if (userExists(username)) {
        return false; // User already exists
    }

    if (database.isEmpty()) {
        rights = 1;
    }

    QJsonObject newUser;
    newUser["password"] = password;
    newUser["rights"] = rights;
    QJsonArray profiles;
    profiles.append("default");
    newUser["profiles"] = profiles;

    database[username] = newUser;
    saveDatabase();

    return true;
}

bool UserDatabase::validateUser(const QString &username, const QString &password) {
    if (!userExists(username)) {
        return false; // User does not exist
    }

    QJsonObject user = database[username].toObject();
    return (user["password"].toString() == password);
}

bool UserDatabase::userExists(const QString &username) {
    return database.contains(username);
}

void UserDatabase::loadDatabase() {
    QFile file(filePath);
    if (!file.open(QIODevice::ReadOnly)) {
        return; // File does not exist or cannot be read, will be created on first user creation
    }

    QByteArray fileData = file.readAll();
    file.close();
    QJsonDocument doc(QJsonDocument::fromJson(fileData));
    database = doc.object();
}

void UserDatabase::saveDatabase() {
    QFile file(filePath);
    if (!file.open(QIODevice::WriteOnly)) {
        return; // Unable to open file for writing
    }

    QJsonDocument doc(database);
    file.write(doc.toJson());
    file.close();
}

bool UserDatabase::changeUserRights(const QString &username, int newRights) {
    if (!userExists(username)) {
        return false; // User does not exist
    }

    QJsonObject user = database[username].toObject();
    int currentRights = user["rights"].toInt();
    if (currentRights == 1 && newRights != 1) {
        return false; // Cannot change rights from 1
    }
    if (newRights == 1) {
        return false; // Cannot change rights to 1
    }
    user["rights"] = newRights;
    saveDatabase();
    return true;
}


bool UserDatabase::deleteUser(const QString &username) {
    if (!userExists(username)) {
        return false; // User does not exist
    }

    database.remove(username);
    saveDatabase();
    return true;
}


bool UserDatabase::addProfile(const QString &username, const QString &profileName) {
    if (!userExists(username)) {
        return false; // User does not exist
    }

    QJsonObject user = database[username].toObject();
    QJsonArray profiles = user["profiles"].toArray();

    // Check if the profile already exists before appending
    if (profiles.contains(profileName)) {
        return false; // Profile already exists
    }

    profiles.append(profileName);
    user["profiles"] = profiles;

    // Replace the updated user object back into the database
    database[username] = user;
    saveDatabase();

    return true;
}

bool UserDatabase::deleteProfile(const QString &username, const QString &profileName) {
    if (!userExists(username)) {
        return false; // User does not exist
    }

    QJsonObject user = database[username].toObject();
    QJsonArray profiles = user["profiles"].toArray();

    // Check if the profile exists before attempting to delete
    int profileIndex = -1;
    for (int i = 0; i < profiles.size(); ++i) {
        if (profiles[i].toString() == profileName) {
            profileIndex = i;
            break;
        }
    }

    if (profileIndex == -1) {
        return false; // Profile does not exist
    }

    profiles.removeAt(profileIndex);
    user["profiles"] = profiles;

    database[username] = user;
    saveDatabase();

    return true;
}

QJsonObject UserDatabase::getUserDetails(const QString &username) {
    if (userExists(username)) {
        return database[username].toObject();
    }
    return QJsonObject(); // Return an empty object if the user doesn't exist
}

QJsonObject UserDatabase::getAllUsers() {
    return database;
}

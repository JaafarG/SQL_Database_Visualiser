#include "sessionmanager.h"
#include "qjsonarray.h"

SessionManager& SessionManager::instance() {
    static SessionManager instance; // Guaranteed to be destroyed and instantiated on first use
    return instance;
}

void SessionManager::loginUser(const QString &username, const QJsonObject &userDetails) {
    currentUsername = username;
    currentUserRights = userDetails["rights"].toInt();
    // Assuming the first profile in the array is the default active profile
    currentUserProfile = userDetails["profiles"].toArray().first().toString();
}

void SessionManager::logoutUser() {
    currentUsername.clear();
    currentUserRights = 0;
    currentUserProfile.clear();
}

QString SessionManager::getCurrentUsername() const {
    return currentUsername;
}

int SessionManager::getCurrentUserRights() const {
    return currentUserRights;
}

QString SessionManager::getCurrentUserProfile() const {
    return currentUserProfile;
}

void SessionManager::setCurrentUserProfile(const QString &profileName) {
    currentUserProfile = profileName;
}

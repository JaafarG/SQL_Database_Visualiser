#ifndef SESSIONMANAGER_H
#define SESSIONMANAGER_H

#include <QString>
#include <QJsonObject>

class SessionManager {
public:
    static SessionManager& instance();

    void loginUser(const QString &username, const QJsonObject &userDetails);
    void logoutUser();
    QString getCurrentUsername() const;
    int getCurrentUserRights() const;
    QString getCurrentUserProfile() const;
    void setCurrentUserProfile(const QString &profileName);

private:
    QString currentUsername;
    int currentUserRights;
    QString currentUserProfile;

    SessionManager() {}
    SessionManager(const SessionManager&) = delete;
    SessionManager& operator=(const SessionManager&) = delete;
};

#endif // SESSIONMANAGER_H

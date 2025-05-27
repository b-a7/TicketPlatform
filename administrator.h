#ifndef ADMINISTRATOR_H
#define ADMINISTRATOR_H
#include "user.h"

#include <string>

// create, modify, delete any user

class Artist;

class Administrator : public User {
    friend class Artist;

public:

    Administrator();
    // constructor
    Administrator(const std::string& username, const std::string& password);

    //string getType() const override {return "Artist";}

    // create user
    void create_user(Platform& platform);

    // modify will be a clear, and then rewrite for a specific user
    void modifyUser(Platform& platform);

    // delete user provided username
    void deleteUser(Platform& platform);

    void createAdmin(Platform& platform);

    std::string getType() const override { return "Administrator"; }

    void adminDashboard(Platform& platform);

};

#endif // ADMINISTRATOR_H

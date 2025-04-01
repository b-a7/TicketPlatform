#ifndef ADMINISTRATOR_H
#define ADMINISTRATOR_H

#include "user.h"
#include <string>

// create, modify, delete any user

class Administrator : public User {
public:

    // constructor
    Administrator(const std::string& username, const std::string& password);

    //string getType() const override {return "Artist";}

    // create user
    void create_user();

    // modify will be a clear, and then rewrite for a specific user
    void modifyUser(User* user);

    // delete user provided username
    void deleteUser(User* user);

    void createAdmin(const std::string& username, const std::string& password);


};

#endif // ADMINISTRATOR_H

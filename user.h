#ifndef USER_H
#define USER_H

#include <iostream>
#include <string>
#include <vector>

class User {

protected:
    std::string username;
    std::string password;

    // vector of pointers to User objects (base class)
        // ** NEED to MANUALLY clean up memory of list
    static std::vector<User*> user_list;    // static shares the list for all User objects rather than each user having its own list

public:
    // Empty constructor
    User();

    // Parametized constructor
    User(const std::string& username, const std::string& password);

    // Copy constructor
    User(const User& other);

    // Destructor virtual to ensure derived class destructor is called
    virtual ~User();

    const std::string getUsername();

    const std::string getPassword();

/*    // gets type of user, redefined within each sub class
    virtual std::string getType() const; */       // returns to user what type of USER they are

    // receives reference to user object and adds this to current list
    void addUser(User& user);

    // virtual for initial display that can be overriden
    virtual void displayInfo() { std::cout << "Username: " << this->username << std::endl;
                                 std::cout << "Password: " << this->password << std::endl; }

    static void cleanup();

    static int getNumUsers();

    void run();

};



// virtual is needed when the derived class needs to overwrite the method of the base class

#endif // USER_H

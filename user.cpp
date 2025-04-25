#include "user.h"
#include "platform.h"

#include <iostream>

using namespace std;

// Define the static member
vector<User*> User::user_list;

User::User() {}

User::User(const string& username, const string& password) {
    this->username = username;
    this->password = password;

}

// Copy constructor
User::User(const User& other) {

    this->username = other.username;
    this->password = other.password;

    //addUser(*this);
}

void User::create_user(const string& username, const string& password, Platform& platform) {

    User* user = new User(username, password);

    platform.addUser(user);

}

User::~User() {
}

// const string User::getType() {
//     return "User";
// }

const string User::getUsername() {

    return username;
}

const string User::getPassword() {

    return password;
}

  // returns to user what type of USER they are
std::string User::getType() const {
    return "User";
}



// // receives reference to user object and adds this to current list
// void User::addUser(User& user) {

//     user_list.push_back(&user);           // need to give address as the vector holds pointers to Users, not objects themselves

// }

// int User::getNumUsers() {

//     return user_list.size();
// }


// // cleanup for user_list memory
// void User::cleanup() {
//     for (User* user : user_list) {
//         delete user;
//     }
//     user_list.clear();
// }


// void User::run() {

//     cout << "\n******-Welcome to the Ticket Platform-******\n" << endl;

//     cout << "\n" << endl;
// }




#include "platform.h"
#include "administrator.h"
#include "artist.h"
#include "location.h"
#include "attendee.h"
#include "event.h"
#include "user.h"
#include "VIP_Attendee.h"
#include <iostream>

using namespace std;

Platform::Platform() {

    user_list = std::vector<User*>();
    locations = std::vector<Location*>();
}

Platform::~Platform() {
    for (User* user : user_list) delete user;
    for (Location* loc : locations) delete loc;
}

void Platform::addUser(User *user) {

    if (user) user_list.push_back(user);
}

int Platform::getNumUsers() const {
    return user_list.size();
}

// search in list of users, using get
Artist* Platform::findArtistByName(const std::string& name) {

    for (User* user : user_list) {

        // dynamic cast will fail if user pointed to currently is not of type artist
        if (Artist* artist = dynamic_cast<Artist*>(user) ) {
            if (artist->getName() == name) {
                // need to return artist
                return artist;
            }
        else {
            cout << "artist not found" << endl;
            return nullptr;
        }
    }
    }
    return nullptr;
}

Location* Platform::findLocationByName(const std::string& name) {

    for (Location* loc : locations) {
        if (loc->getLocationName() == name) return loc;
    }
    cout << "location not found CHECK" << endl;
    return nullptr;
}

void Platform::displayUsers() {

    cout << "Current Users: " << endl;

    for (size_t i = 0; i < user_list.size(); i++) {

        // display user type
        cout << user_list[i]->getType() << endl;

        // display user info
    }

}

void Platform::displayAvailableLocations() {

    cout << "Available locations: " << endl;

    for (size_t i = 0; i < locations.size(); i++) {

        // check if location is available
        if (locations[i]->check_isAvailable() == true) {

            // display location
            cout << locations[i]->getLocationName() << endl;
        }
    }
}



//bool is_available(const std::string& date) const;



// Placeholder for main loop: login, create users, events, etc.
void Platform::run() {

    // move this to main ****
    //Platform platform;

    cout << "\n******-Welcome to the Ticket Platform-******\n\n";


    }
    else {
        cout << "What type of User are you?" << endl;
        cout << "   1)   Attendee " << endl;
        cout << "   2)   Artist" << endl;
        cout << "   3)   Administrator" << endl;
        cout << "   4)   VIP Attendee" << endl;
        cout << "Enter selection (1-4): ";

        cin >>
    }


    while (1) {

        if (initial_response == 'y' or "Y") {

        }
    }


    Artist artist;
    Administrator admin;

    Location* arena1 = new Location();
    arena1->setLocationName("Johnys location");
    locations.push_back(arena1);

    // Location arena2;
    // locations.push_back(&arena2);

   // if (user) user_list.push_back(user);


    // add to location vector

    artist.createArtist("Jerry11", "abc", "Jerry", "Classical", "once upon a time", *this);

    //displayUsers();

    //admin.create_user(*this);

    displayUsers();

    displayAvailableLocations();

}





// to ask about - do we need to consider all users are new users or we need to save data from previously created users
// string initial_response;
// cout << "Do you have an account? (Y / N)" << endl;
// cin >> initial_response;

// if (initial_response == 'y' || initial_response == "Y") {
//     cout << "Enter login details: " << endl;
//     cout << "Enter username: " << endl;
//     cin >> username;
//     cout << "Enter password: " << endl;
//     cin >> password;


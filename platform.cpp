#include "platform.h"
#include "administrator.h"
#include "artist.h"
#include "location.h"
#include "attendee.h"
#include "event.h"
#include "user.h"
#include "VIP_Attendee.h"
#include <iostream>
#include <fstream>
#include <sstream>


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

    cout << "\n---- Current Users ----" << endl;

    for (size_t i = 0; i < user_list.size(); i++) {

        User* user = user_list[i];
        cout << "[" << i << "] " << user->getType() << endl;
        cout << "    Username: " << user->getUsername() << endl;

        if (Artist* artist = dynamic_cast<Artist*>(user)) {
            cout << "    Style: " << artist->getStyle() << endl;
            cout << "    Bio: " << artist->getDescription() << endl;
        }
        else if (VIP_attendee* vip = dynamic_cast<VIP_attendee*>(user)) {
            cout << "    VIP ID: " << vip->getID() << endl;
            cout << "    Wallet: $" << vip->getWallet() << endl;
        }
        else if (Attendee* attendee = dynamic_cast<Attendee*>(user)) {
            cout << "    ID: " << attendee->getID() << endl;
            cout << "    Wallet: $" << attendee->getWallet() << endl;
        }

        // // display user type
        // cout << user_list[i]->getType() << endl;

        // display user info
        cout << endl;
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

//void Platform::displayEvents() {}


//bool is_available(const std::string& date) const;


// write user to file in proper csv format
void Platform::saveUserstoFile(const string& filename) {

    // ofs represents 'output file stream'
    ofstream ofs(filename, ios::out);

    if (!ofs) {
        throw runtime_error("Error saving to file: " + filename);
        return;
    }

    for (User* user : user_list) {
        ofs << user->getType() << ",";
        ofs << user->getUsername() << "," << user->getPassword() << ",";

        // if artist need name, style, description
        if (Artist* artist = dynamic_cast<Artist*> (user)) {
            ofs << artist->getName() << "," << artist->getStyle() << "," << artist->getDescription();
        }

        // ID, wallet
        else if (Attendee* attendee = dynamic_cast<Attendee*> (user) ) {
            ofs << attendee->getID() << "," << attendee->getWallet();
        }

        // ID, wallet
        else if (VIP_attendee* vip_attendee = dynamic_cast<VIP_attendee*> (user) ) {
            ofs << vip_attendee->getID() << "," << vip_attendee->getWallet();
        }

        else if (Administrator* admin = dynamic_cast<Administrator*>(user)) {
            // No extra fields, so nothing to add
        }

        else {
            throw runtime_error("Unknown user type: " + user->getType());
        }
        ofs << "\n";  // New line after each user

    }
    ofs.close();

}


// Loadusers = read data mode == ifstream
// 1) need to get line, examine type from first word UNTIL comma , then create object, fill in data fields with info

void Platform::loadUsersFromFile(const string& filename) {

    ifstream ifs(filename);

    if (!ifs) {
        throw runtime_error("Cannot open file for reading: " + filename);
    }

    // clear existing users
    for (User* user : user_list) delete user;
    user_list.clear();


    string line;
    // read each line until getline finds eof
    while (getline(ifs, line)) {

        // Stringstream to parse line acts as internal buffer
        stringstream ss(line);

        string type, username, password;
        // Get type up to comma
        getline(ss, type, ',');
        getline(ss, username, ',');
        getline(ss, password, ',');

        if (type == "Artist") {
            string name, style, description;
            getline(ss, name, ',');
            getline(ss, style, ',');
            getline(ss, description, ',');
            // add line for event list
            Artist* artist = new Artist(username, password, name, style, description);
            user_list.push_back(artist);

            ////**** space here for event list specific to artist
        }
        else if (type == "Attendee") {
            string ID;
            double wallet;
            getline(ss, ID, ',');

            // for double better to just map straight from ss instead of getline
            ss >> wallet;
            Attendee* attendee = new Attendee(username, password, ID, wallet);
            user_list.push_back(attendee);
        }
        else if (type == "VIP_attendee") {
            string VIP_ID;
            double vip_wallet;
            getline(ss, VIP_ID, ',');
            ss >> vip_wallet;
            VIP_attendee* vip_attendee = new VIP_attendee(username, password, VIP_ID, vip_wallet);
            user_list.push_back(vip_attendee);
        }
        else if (type == "Administrator") {
            Administrator* admin = new Administrator(username, password);
            user_list.push_back(admin);
        }
        else {
            throw runtime_error("Unknown user type in file: " + type);
        }

    }
   // ifs.close();
}

// given user check their username/password against one provided by user and return true or false to proceed
void Platform::loginPage() {

    string username, password;
    cout << "Enter username: ";
    cin >> username;

    cout << "Enter password: ";
    cin >> password;

    for (User* user : user_list) {

        if (user->getUsername() == username && user->getPassword() == password) {
            cout << "Login successful as " << user->getType() << endl;

            if (Administrator* administrator = dynamic_cast<Administrator*>(user)) {
                administrator->adminDashboard(*this);
            }

            if (Artist* artist = dynamic_cast<Artist*>(user)) {
                artist->artistDashboard(*this);
            }

            if (Attendee* attendee = dynamic_cast<Attendee*>(user)) {
                attendee->attendeeDashboard(*this);
            }

            if (VIP_attendee* attendee = dynamic_cast<VIP_attendee*>(user)) {
                //VIP_attendee->VIP_Dashboard(this*);
            }
            return;
        }
    }
    // check above credentials against actual user details
    cout << "\n!!!!!!!!!!!!!!!!!!!!!!\n";
    cout << "Login failed!" << endl;
    cout << "\n!!!!!!!!!!!!!!!!!!!!!!";

}

// Placeholder for main loop: login, create users, events, etc.
int Platform::run() {

    // move this to main ****
    //Platform platform;
    // string initial_response, response;


    loadUsersFromFile("users.txt");
    while (true) {

        string choice;
        cout << "\n******-Welcome to the Ticket Platform-******\n\n";
        cout << "1. Login" << endl;
        cout << "2. Create New User" << endl;

        cout << "0. Exit" << endl;

        cin >> choice;

        if (choice == "0") {
            saveUserstoFile("users.txt");
            return 0;
        }

        else if (choice == "1") {

            loginPage();
        }

        else if (choice == "2") {

            // distinguishes what user is to be created, creates and saves to user_list, and also SAVES to FILE
            //handle_user_creation();

            User* newUser = handle_user_creation();
            if (newUser) {
                if (Attendee* attendee = dynamic_cast<Attendee*>(newUser)) {
                    attendee->attendeeDashboard(*this);
                }
                else if (Artist* artist = dynamic_cast<Artist*>(newUser)) {
                    artist->artistDashboard(*this);
                }
                else if (Administrator* admin = dynamic_cast<Administrator*>(newUser)) {
                    admin->adminDashboard(*this);
                }
                else if (VIP_attendee* vip = dynamic_cast<VIP_attendee*>(newUser)) {
                    vip->attendeeDashboard(*this); // use same as Attendee
                }
            }
        }
            // ******bring to relevant user dashboard screens ******


        }


    }





// Return created user to route directly to their dashboard
User* Platform::handle_user_creation() {

    while (true) {

        cout << "\nWhat type of user do you want to create?" << endl;
        cout << "-" << endl;
        cout << "   1)   Attendee " << endl;
        cout << "   2)   Artist" << endl;
        cout << "   3)   Administrator" << endl;
        cout << "   4)   VIP Attendee" << endl;

        cout << " \n  (0)   Return Back" << endl;
        cout << "-" << endl;
        cout << "Enter selection (1-4): ";

        string response;
        cin >> response;

        if (response == "1") {
            Attendee attendee_temp;

            // *** username/password/ID removed here because they are all handled within createAttendee
            attendee_temp.createAttendee(*this);
            saveUserstoFile("users.txt");
            displayUsers();
            break;
        }

        else if (response == "2") {
            Artist artist_temp;

            artist_temp.createArtist(*this);
            saveUserstoFile("users.txt");
            displayUsers();
            break;
        }

        else if (response == "3") {
            Administrator admin_temp;

            admin_temp.createAdmin(*this);
            saveUserstoFile("users.txt");
            displayUsers();
            break;
        }

        else if (response == "4") {
            VIP_attendee VIP_temp;

            VIP_temp.createVIPAttendee(*this);
            saveUserstoFile("users.txt");
            displayUsers();
            break;
        }

        else if (response == "0") {
            break;
        }

        else {
            cout << "Invalid selection. Please select a number from 0-4." << endl;
        }
    }
}


// original testing WORKING
   //  Artist artist;
   //  Administrator admin;

   //  Location* arena1 = new Location();
   //  arena1->setLocationName("Johnys location");
   //  locations.push_back(arena1);

   //  // Location arena2;
   //  // locations.push_back(&arena2);

   // // if (user) user_list.push_back(user);


   //  // add to location vector

   //  artist.createArtist("Jerry11", "abc", "Jerry", "Classical", "once upon a time", *this);

   //  this->saveUserstoFile("users.txt"); // Saves to ./users.txt

   //  //displayUsers();

   //  //admin.create_user(*this);

   //  displayUsers();

   //  displayAvailableLocations();







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


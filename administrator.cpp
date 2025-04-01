#include "administrator.h"
#include "artist.h"
#include "attendee.h"
#include "VIP_Attendee.h"

#include <iostream>

class VIP_attendee;

using namespace std;

Administrator::Administrator(const string& username, const string& password) {
    this->username = username;
    this->password = password;
}

// create user:
    /* 1) user constructor called and creates a new User object

       2) new user added to the end of the users vector
    */
void Administrator::createAdmin(const string& username, const string& password) {

    User* admin = new Administrator(username, password);

    addUser(*admin);      // add user to end of user_list

    cout << "User of type ADMINISTRATOR created" << endl;

}

// create user
void Administrator::create_user() {

    string temp_username, temp_password;
    int user_type;
    int isVIP;

    cout << "What type of User do you want to create?" << endl;
    cout << "   1)   Attendee " << endl;
    cout << "   2)   Artist" << endl;
    cout << "   3)   Administrator" << endl;
    cout << "Enter selection (1-3): ";

    cin >> user_type;

    cout << "Enter username: " << endl;
    cin >> username;
    cout << "Enter password: " << endl;
    cin >> password;

    switch(user_type) {


        case 1: {
            cout << " Is the Attendee VIP? " << endl;
            cout << " 1 == YES, 2 == NO\n" << endl;
            cin >> isVIP;
            cin.ignore(numeric_limits<streamsize>::max(), '\n');    // Clears remaining characters (like a newline) in  input buffer aftr reading int

            if (isVIP == 1) {
                // VIP attendee
                string VIP_ID;
                VIP_ID = createVIPID();
                createVIPAttendee(username, password, VIP_ID);
            }

            // normal attendeee
            else {
                string ID;
                ID = createAttendeeID();
                createAttendee(username, password, ID);
                 }
            break;
        }

        // CASE artist
        case 2: {
            string name, style, description;

            name = defineArtistName();
            style = defineArtistStyle();
            description = defineArtistBio();

            createArtist(username, password, name, style, description);

            break;
        }

            // CASE admin
        case 3: {
            createAdmin(username, password);

            break;
        }
    }
}


// modify will be a clear, and then rewrite for a specific user
void modifyUser(User* user) {
    return;

}

// delete user provided username
void deleteUser(User* user) {
    return;
}

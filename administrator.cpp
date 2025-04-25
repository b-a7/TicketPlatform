#include "administrator.h"
#include "artist.h"
#include "attendee.h"
#include "VIP_Attendee.h"

#include <iostream>

class VIP_attendee;

using namespace std;

Administrator::Administrator() {};

Administrator::Administrator(const string& username, const string& password) {
    this->username = username;
    this->password = password;
}

// create user:
    /* 1) user constructor called and creates a new User object

       2) new user added to the end of the users vector
    */
void Administrator::createAdmin(const string& username, const string& password, Platform& platform) {

    User* admin = new Administrator(username, password);

    platform.addUser(admin);      // add user to end of user_list

    cout << "User of type ADMINISTRATOR created" << endl;

}

// create user
void Administrator::create_user(Platform& platform) {

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

                // creating empty VIP_attendee object (temp) to fill in fields for
                VIP_attendee VIP_attendee_temp;

                VIP_ID = VIP_attendee_temp.createVIPID(platform);
                VIP_attendee_temp.createVIPAttendee(username, password, VIP_ID, platform);
                cout << "This worked, password" << endl;
            }

            // normal attendeee
            else {
                string ID;
                Attendee attendee_temp;
                ID = attendee_temp.createAttendeeID(platform);
                attendee_temp.createAttendee(username, password, ID, platform);
                // or can make freind class and use create attendee normally, or modify the already made attendee object with info given
                 }
            break;
        }

        // CASE artist
        case 2: {
            string name, style, description;

            Artist artist1;

            name = artist1.defineArtistName();
            style = artist1.defineArtistStyle();
            description = artist1.defineArtistBio();        // -- change to just set this new artist object with given fields instead of create new object

            // use of undeclared 'defineartistname' -- how can this be fixed --> can I use 'friend class'
            // name = defineArtistName();
            //style = defineArtistStyle();
            //description 3= defineArtistBio();

            artist1.createArtist(username, password, name, style, description, platform);

            break;
        }

            // CASE admin
        case 3: {

            createAdmin(username, password, platform);

            break;
        }
    }
}


// modify user can just override specific fields of a user with given info
void modifyUser(User* user) {
    return;

}

// delete user provided username
void deleteUser(User* user) {
    return;
}

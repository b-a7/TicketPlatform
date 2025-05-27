#include "administrator.h"
#include "artist.h"
#include "attendee.h"
#include "VIP_Attendee.h"

#include <limits>
#include <iostream>

class VIP_attendee;

using namespace std;

Administrator::Administrator() {}

Administrator::Administrator(const string& username, const string& password) {
    this->username = username;
    this->password = password;
}

// create user:
    /* 1) user constructor called and creates a new User object

       2) new user added to the end of the users vector
    */
void Administrator::createAdmin(Platform& platform) {

    string username, password;
    cout << "Enter username: ";
    cin >>  username;

    cout << "Enter password: ";
    cin >> password;

    User* admin = new Administrator(username, password);

    platform.addUser(admin);      // add user to end of user_list

    cout << "User of type ADMINISTRATOR created" << endl;

}

// create user
void Administrator::create_user(Platform& platform) {

    string temp_username, temp_password;
    int user_type;
    int isVIP;

    cout << "\nWhat type of User do you want to create?" << endl;
    cout << "--------------------------" << endl;
    cout << "   1)   Attendee " << endl;
    cout << "   2)   Artist" << endl;
    cout << "   3)   Administrator" << endl;
    cout << "--------------------------" << endl;
    cout << "Enter selection (1-3): ";

    cin >> user_type;

    // cout << "Enter username: " << endl;
    // cin >> username;
    // cout << "Enter password: " << endl;
    // cin >> password;

    switch(user_type) {


        case 1: {
            cout << " Is the Attendee VIP? " << endl;
            cout << " 1 == YES, 2 == NO\n" << endl;
            cin >> isVIP;
            cin.ignore(numeric_limits<streamsize>::max(), '\n');    // Clears remaining characters (like a newline) in  input buffer aftr reading int

            if (isVIP == 1) {

                // creating empty VIP_attendee object (temp) to fill in fields for
                VIP_attendee VIP_attendee_temp;

                VIP_attendee_temp.createVIPAttendee(platform);
                cout << "This worked, password" << endl;
            }

            // normal attendeee
            else {
                string ID;
                Attendee attendee_temp;
                ID = attendee_temp.createAttendeeID(platform);

                // *** username/password/ID removed here because they are all handled within createAttendee
                attendee_temp.createAttendee(platform);
                // or can make friend class and use create attendee normally, or modify the already made attendee object with info given
                 }
            break;
        }

        // CASE artist
        case 2: {

            // Temporary and empty artist object to call create upon
            Artist artist1;

            artist1.createArtist(platform);
            break;
        }

            // CASE admin
        case 3: {

            createAdmin(platform);

            break;
        }
    }
}


// modify user can just override specific fields of a user with given info
void Administrator::modifyUser(Platform& platform) {

    string username;
    cout << "\nEnter the username of the user you want to delete: ";
    cin >> username;

    for (User* user : platform.user_list) {
        if (user->getUsername() == username) {
            cout << "User found. " << endl;

            bool done = false;

            while (!done) {

                cout << "\nWhat would you like to modify?\n";
                cout << "--------------------------" << endl;
                cout << "1. Password" << endl;

                // check if user is type Artist by dynamic cast test (which returns true if cast is complete
                if (Artist* artist = dynamic_cast<Artist*>(user)) {
                    cout << "2. Name" << endl;
                    cout << "3. Musical Style" << endl;
                    cout << "4. Artist description" << endl;
                }

                cout << "0. Exit" << endl;
                cout << "Choice: ";
                int choice;
                cin >> choice;

                switch (choice) {
                    case 1: {

                        string newPassword;
                        cout << "Enter new password: ";
                        cin >> newPassword;
                        user->setPassword(newPassword);
                        cout << "Password updated " << endl;
                        break;
                    }
                    case 2: {

                        if (Artist* artist = dynamic_cast<Artist*>(user)) {
                            string newStyle;
                            cout << "Enter new style: ";


                            getline(cin, newStyle);
                            artist->updateStyle(newStyle);
                            cout << "Style Updated" << endl;
                        }

                        else {
                            // *** error here
                        }
                        break;
                    }
                    case 3: {

                        if (Artist* artist = dynamic_cast<Artist*>(user)) {
                            string newDescription;
                            cout << "Enter new description: ";

                            // flush newline before getline
                            cin.ignore();
                            getline(cin, newDescription);
                            cout << "Description updated." << endl;
                        }
                        break;

                    }
                    case 0:
                        done = true;
                        break;

                    default:
                        cout << "Invalid choice. " << endl;
                        break;

                }
            }

            return;

        }
    }
}


// delete user provided username
void Administrator::deleteUser(Platform& platform) {

    string username;
    cout << "\nEnter the username of the user you want to delete: ";
    cin >> username;

    for (auto it = platform.user_list.begin(); it != platform.user_list.end(); ++it) {
        if ((*it)->getUsername() == username) {
            delete *it;
            platform.user_list.erase(it);
            cout << "User <" << username << "> deleted successfully" << endl;
            return;     // break immediately from iterator loop after deletion
        }
    }

    cout << "\n!!!!!\n" << endl;
    cout << "User not found" << endl;
    cout << "\n!!!!!\n" << endl;

}

void Administrator::adminDashboard(Platform& platform) {

    // admin can create, modify, delete user

    while (true) {

        int choice;
        cout << "\n--------------------------" << endl;
        cout << "Administrator Menu -- select an option: " << endl;
        cout << "--------------------------" << endl;
        cout << "   1)   Create User " << endl;
        cout << "   2)   Modify User" << endl;
        cout << "   3)   Delete User" << endl;
        cout << "   4)   View all Users" << endl;


        cout << " \n  (0)   Return Back" << endl;
        cout << "--------------------------" << endl;
        cout << "Enter selection (0-4)): ";

        cin >> choice;

        // cin.fail() is for if int is provided instead of string, if so, fail() returns TRUE
        if (cin.fail()) {
            cin.clear();
            // Flushes the input buffer: clears any leftover characters (e.g., newline) to prevent input issues
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid input. Please enter a number.\n";
            continue;
        }

        if (choice == 1) {
            create_user(platform);
        }

        else if (choice == 2) {
            modifyUser(platform);
        }

        else if (choice == 3) {
            deleteUser(platform);
        }

        else if (choice == 4) {
            // displayUsers function
            platform.displayUsers();
        }

        else if (choice == 0) {
            break;
        }

        else {
            cout << "Invalid input! Enter selection (0-4)" << endl;
        }
    }

}

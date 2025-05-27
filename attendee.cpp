#include "attendee.h"
#include "platform.h"

using namespace std;

Attendee::Attendee() {}

Attendee::Attendee(const string& username, const string& password,
             const string& ID, double initial_funds) {

    this->username = username;
    this->password = password;
    this->ID = ID;
    this->wallet = initial_funds;
}

void Attendee::addFunds(double amount) {

    if (amount < 0) {
        throw invalid_argument("Invalid add amount");
    }
    else {
        this->wallet = wallet + amount;
    }
}

void Attendee::viewTickets() {

    // display vector of available tickets
    return;
}

//user.event.buyticket() -- will be implementation
void Attendee::buyTicket() {

    // must 1) give user ticket type 2) minus 1 ticket available 3) minus funds from account
    return;
}

void Attendee::displayEvents() {
    return;
}


double Attendee::getWallet() const {
    return this->wallet;
}

// method which asks user for attendee info then creates attendee using constructor and adds to user_list
void Attendee::createAttendee(Platform& platform) {

    string username, password;

    cout << "Enter username: ";
    cin >> username;
    cout << "Enter password: ";
    cin >> password;

    string ID = createAttendeeID(platform);

    User* attendee = new Attendee(username, password, ID);

    platform.addUser(attendee);

    cout << "User of type Attendee created" << endl;

}

const string Attendee::createAttendeeID(Platform& platform) {

    string ID = to_string(platform.getNumUsers());

    //cout << "Test ID: " << ID << endl;

    return ID;
}

void Attendee::attendeeDashboard(Platform& platform) {

    //need to actually move to the user in list


    while (true) {

        cout << "\n--------------------------" << endl;
        cout << "Attendee Menu -- select an option: " << endl;
        cout << "--------------------------" << endl;
        cout << "   1)   View Profile " << endl;
        cout << "   2)   View my Tickets" << endl;
        cout << "   3)   Purchase Ticket" << endl;
        cout << "   4)   View Available Events" << endl;
        cout << "   5)   Add Funds " << endl;
        cout << "   6)   View Artist Info" << endl;

        cout << " \n  (0)   Return Back" << endl;
        cout << "--------------------------" << endl;
        cout << "Enter selection (0-6)): ";

        int choice;
        cin >> choice;

        if (choice == 1) {
            cout << "\nUsername: " << this->getUsername() << "\n";
            cout << "Attendee ID: " << this->getID() << "\n";
            cout << "Wallet: $" << this->getWallet() << "\n";
        }


        else if (choice == 2) {

        }

        else if (choice == 3) {

        }

        else if (choice == 4) {


        }

        else if (choice == 5) {
            double money;
            cout << "\nEnter amount of money to add: " << endl;
            cin >> money;
            this->addFunds(money);
            cout << "\n" << "$ " << money << " Successfully added to wallet" << endl;
        }


        else if (choice == 0) {
            break;
        }

        else {
            cout << "Invalid input! Enter selection (0-4)" << endl;
        }

        if (cin.fail()) {
            cin.clear();
            // Flushes the input buffer: clears any leftover characters (e.g., newline) to prevent input issues
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid input. Please enter a number.\n";
            continue;
        }
    }


}

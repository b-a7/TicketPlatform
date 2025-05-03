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




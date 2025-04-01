#include "attendee.h"

using namespace std;


Attendee::Attendee(const string& username, const string& password,
             const string& ID, double initial_funds = 0.0) {

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

void Attendee::viewTicekts() {

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

void Attendee::createAttendee(const string& username, const string& password,
                              const string& ID) {

    User* Attendee = new Attendee(username, password, ID);

    addUser(Attendee);

    cout << "User of type Attendee created" << endl;

}

const string Attendee::createAttendeeID() {

    string ID = tostring(getNumUsers());

    cout << "Test ID: " << ID << endl;

    return ID;
}




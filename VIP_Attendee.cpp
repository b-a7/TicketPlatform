#include "VIP_Attendee.h"

using namespace std;

// Define the static member (this must be done in the .cpp file, not the header)
vector<Ticket*> VIP_attendee::SecondaryMarket;


VIP_attendee::VIP_attendee() {
    // Empty constructor, no special initialization
}

VIP_attendee::VIP_attendee(const std::string& username, const std::string& password,
                           const std::string& VIP_ID, double initial_funds)
    : Attendee(username, password, VIP_ID, initial_funds)
{
    this->ID = VIP_ID;
}

//     : Attendee(username, password, VIP_ID), funds(initial_funds) // Initialize base class and funds


VIP_attendee::~VIP_attendee() {

}

void VIP_attendee::buyVIPticket() {
    return;
}

void VIP_attendee::sellVIPticket() {
    return;
}


void VIP_attendee::createVIPAttendee(Platform& platform) {


    string username, password;
    cout << "Enter username: ";
    cin >>  username;

    cout << "Enter password: ";
    cin >> password;

    string VIP_ID = createVIPID(platform);

    User* VIP_attendee1 = new VIP_attendee(username, password, VIP_ID);

    platform.addUser(VIP_attendee1);

    cout << "User of type VIP Attendee created" << endl;

}

const string VIP_attendee::createVIPID(Platform& platform) {

    string VIP_ID = "VIP-" + to_string(platform.getNumUsers());

    //cout << VIP_ID << endl;

    return VIP_ID;
}

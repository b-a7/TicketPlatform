#include "VIP_Attendee.h"

using namespace std;

// Define the static member (this must be done in the .cpp file, not the header)
vector<Ticket*> VIP_attendee::SecondaryMarket;


VIP_attendee::VIP_attendee(const std::string& username, const std::string& password,
                           const std::string& VIP_ID, double initial_funds)
    : Attendee(username, password, VIP_ID)
{
    this->ID = VIP_ID;
}


VIP_attendee::~VIP_attendee() {

}
void VIP_attendee::buyVIPticket() {
    return;
}

void VIP_attendee::sellVIPticket() {
    return;
}


void VIP_attendee::createVIPAttendee(const string& username, const string& password,
                                     const string& VIP_ID ) {

    User* VIP_attendee1 = new VIP_attendee(username, password, VIP_ID);

    addUser(*VIP_attendee1);

    cout << "User of type VIP Attendee created" << endl;

}

const string VIP_attendee::createVIPID() {

    string VIP_ID = "VIP-" + to_string(getNumUsers());

    //cout << VIP_ID << endl;

    return VIP_ID;
}

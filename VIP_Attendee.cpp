#include "VIP_Attendee.h"

using namespace std;

// Define the static member (this must be done in the .cpp file, not the header)
vector<Ticket*> VIP_attendee::SecondaryMarket;


VIP_attendee::VIP_attendee(const std::string& username, const std::string& passsword,
             const std::string& VIP_ID, double initial_funds = 0.0);

VIP_attendee::VIP_attendee();

void VIP_attendee::buyVIPticket();

void VIP_attendee::sellVIPticket();


void VIP_attendee::createVIPAttendee(const std::string& username, const std::string& passsword,
                                     const std::string& VIP_ID ) {

    User* VIP_attendee = new VIP_attendee(username, password, VIP_ID);

    addUser(VIP_attendee);

    cout << "User of type VIP Attendee created" << endl;

}

const string VIP_attendee::createVIPID() {

    string VIP_ID = "VIP-" + to_string(getNumUsers());

    //cout << VIP_ID << endl;

    return VIP_ID;
}

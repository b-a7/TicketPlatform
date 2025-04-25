#ifndef ATTENDEE_H
#define ATTENDEE_H

#include "user.h"
#include "platform.h"

// forward declarations tell compiler there's a class Ticket defined in our code
class Event;
class Ticket;

class Attendee : public User {

    // protected so VIPAttendee can access these
protected:
    std::string ID;     // attendee ID
    double wallet;
    std::vector<Ticket*> ticket_list ; // ticket list vector

public:

    // Consutrctor
    Attendee(const std::string& username, const std::string& passsword,
             const std::string& ID, double initial_funds = 0.0);

    Attendee();

    // Wallet management
    void addFunds(double amount);

    // Ticket management
    void viewTickets();     // maybe add a checkAvailableTicket
    void buyTicket();

    // View events
    void displayEvents();

    // getter for wallet amount, returns wallet value, this is like 'displaywallet'
    double getWallet() const;

    //std::string getType() const override {return "Attendee";}

    void createAttendee(const std::string& username, const std::string& password,
                                  const std::string& ID,  Platform& platform);

    const std::string createAttendeeID(Platform& platform);

    std::string getType() const override { return "Attendee"; }


};

#endif // ATTENDEE_H

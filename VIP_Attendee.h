#ifndef VIP_ATTENDEE_H
#define VIP_ATTENDEE_H

#include "user.h"
#include "attendee.h"

class Attendee;
class Ticket;


class VIP_attendee : public Attendee {
private:

    static std::vector<Ticket*> SecondaryMarket;   // static shares this market with entire VIP_attendee class

public:

    // Consutrctor -- given VIP ID to distinguish between them and normal attendees
    VIP_attendee(const std::string& username, const std::string& passsword,
                 const std::string& VIP_ID, double initial_funds = 0.0);


    ~VIP_attendee();

    // VIP extra privelages -- buy/sell completed in SECONDARY market
    void buyVIPticket();

    void sellVIPticket();

    void createVIPAttendee(const std::string& username, const std::string& passsword,
                           const std::string& VIP_ID );

    const std::string createVIPID();

};

#endif // VIP_ATTENDEE_H


#ifndef SECONDARYMARKET_H
#define SECONDARYMARKET_H

#include <vector>
#include "ticket.h"
#include "VIP_Attendee.h"

class Ticket;

class SecondaryMarket {
private:
    std::vector<Ticket*> TicketsforSale;

public:
    // add ticket ultimately
    void sell_ticket(Ticket* ticket, VIP_attendee* seller_ID, double price);

    // buy ticket
    void buy_ticket(Ticket* ticket, VIP_attendee* buyer_ID);    // to buy a ticket funds need to be deducted from a specific buyer

    // display ticket
    void displayTicket() const;


};


#endif // SECONDARYMARKET_H

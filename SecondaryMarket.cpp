#include "SecondaryMarket.h"
#include <iostream>

using namespace std;

void SecondaryMarket :: sell_ticket(Ticket* ticket, VIP_attendee* seller_ID, double price)
{
    ticket->getPrice(price);
    TicketsforSale.push_back(ticket);
    cout << "New ticket at the market for: " << price << "€" << endl;
}

void SecondaryMarket :: buy_ticket(Ticket* ticket, VIP_attendee* buyer_ID)
{
    return;
}

void SecondaryMarket :: displayTicket()
{
    if(TicketsforSale.empty())
    {
        cout << "There are no tickets to buy" << endl;
    }

    else
    {
        cout << "Avaiable tickets:" << endl;
        for(int i=0 ; i<TicketsforSale.size() ; i++)
        {
            cout << i+1 <<" - Ticket " << TicketsforSale[i]->getPrice() << "€" << endl;
        }
    }
}

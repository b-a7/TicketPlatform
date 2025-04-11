#include "ticket.h"
#include <iostream>

using namespace std;

Ticket :: Ticket(Event* event, Attendee* owner, double price)
{
    this->event = event;
    this->owner = owner;
    this->price = price;
}

double Ticket::getPrice() const
{
    return price;
}

void Ticket::setOwner(Attendee *newOwner)
{
    this->owner = newOwner;
    cout << "Ticket has a new owner" << endl;
}

void Ticket::setPrice(double newPrice)
{
    if(newPrice>price)
    {
        price = newPrice;
        cout <<"The price has changed, now is" << newPrice <<"€"<< endl;
    }

    else
    {
        cout << "You have to make a bigger offer" << endl;
    }
}

\#include "event.h"

vector<Event*> Event::event_list;

#include <iostream>
#include <string>

using namespace std;

Event :: Event(Artist* artist, Location* location, const string& date, double price,
              bool isVIP, int available_tickets)
{
    this->artist = artist;
    this->location = location;
    this->date = date;
    this->price = price;
    this->isVIP = isVIP;
    this->available_tickets = available_tickets;
}

string Event :: getDate() const
{
    return date;
}

double Event :: getPrice() const
{
    return price;
}

bool Event :: getVIPStatus() const
{
    return isVIP;
}

int Event :: getAvailableTickets() const
{
    return available_tickets;
}

string Event :: getEventName() const
{
    return event_name;
}



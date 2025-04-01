#include "event.h"
#include "location.h"

#include <iostream>
#include <string>

using namespace std;

vector<Event*> Event::event_list;

Event::Event(Artist* artist, Location* location, const string& date, double price,
              bool isVIP, int available_tickets)
{
    this->artist = artist;
    this->location = location;
    this->date = date;
    this->price = price;
    this->isVIP = isVIP;
    this->available_tickets = available_tickets;
}

const string Event::getDate() const
{
    return this->date;
}

double Event::getPrice() const
{
    return price;
}

bool Event::getVIPStatus() const
{
    return isVIP;
}

int Event::getAvailableTickets() const
{
    return available_tickets;
}

string Event::getEventName() const
{
    return event_name;
}

// void Event::setLocation(const string new_location) {
//     this->location = new_location;
// }


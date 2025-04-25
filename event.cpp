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

//** this will have to go to the location objects attribute location_name
const string Event::getLocation() const {

    return this->location->getLocationName();
}



// void Event::setLocation(const string new_location) {
//     this->location = new_location;
// }

void Event::setEventLocation(const string new_location, Platform& platform) {

    this->location = platform.findLocationByName(new_location);
}


Location* findLocationByName(const std::string& name);


void Event::setDate(const std::string new_date) {
    this->date = new_date;
}

void Event::setPrice(double price) {
    this->price = price;
}

void Event::setAvailableTickets(int tickets_available) {
    this->available_tickets = tickets_available;
}




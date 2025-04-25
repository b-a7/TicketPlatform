#include "location.h"
#include "event.h"

#include <iostream>
#include <string>

using namespace std;

// // declare reserved events vector?

Location::Location() {
    this->is_available = true;
}

Location::Location(const string location_name, const string address, int capacity)
{
    this->location_name = location_name;
    this->address = address;
    this->capacity = capacity;
    this->is_available = true;
}

bool Location::check_isAvailable() {

    return this->is_available;

}


// bool Location::is_Available(const string &date) const
// {
//     for (int i=0 ; i<reserved_events.size(); i++)
//     {
//         if (reserved_events[i]->getDate()==date)
//         {
//             return false;  //Not avaiable
//         }
//     }
//     return true;
// }

// void Location::ReserveEvent(Event* event)
// {
//     if (is_available(event->getDate()))
//     {
//         reserved_events.push_back(event);  // Añade al vector se puede usar esta funcion?
//         cout << "Event reserved in " << location_name << endl;
//     }

//     else
//     {
//         cout << "Not avaible location for this date " << event->getDate() <<endl;
//     }
// }

string Location::getLocationName() const
{
    return location_name;
}

string Location::getAddress() const
{
    return address;
}

int Location::getCapacity() const
{
    return capacity;
}

// void Location::DisplayReservedEvents_array()
// {
//     cout << "Events in " << location_name << ":" << endl;

//     if (reserved_events.size() == 0)
//     {
//         cout << "There are no events" << endl;
//     }

//     else
//     {
//         for (int i=0 ; i<reserved_events.size() ; i++)
//         {
//             cout << "- " << reserved_events[i]->getEventName() << " on " << reserved_events[i]->getDate() << endl;;
//         }
//     }
// }

// string Location::getName() {
//     return this->location_name;
// }

void Location::setLocationName(const string name) {
    this->location_name = name;
}

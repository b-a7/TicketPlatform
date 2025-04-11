#ifndef LOCATION_H
#define LOCATION_H

#include "user.h"
#include "attendee.h"

#include <iostream>
#include <string>

class Location {

private:

    std::string location_name;
    std::string address;

    // determines number of tickets available for an event
    int capacity;


public:

    // Constructor
    Location(const std::string location_name, const std::string addres, int capacity);

    // System check that location is available on desired DATE
    bool is_available(const std::string& date) const;
    void ReserveEvent(Event* event);

    // Getters
    // method to get location
    std::string getLocationName() const;

    std::string getAddress() const;
    std::string getCapacity() const;

    void DisplayReservedEvents_array();

};
#endif // LOCATION_H

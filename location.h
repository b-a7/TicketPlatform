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
    bool is_available;


public:

    // Constructor

    Location();

    Location(const std::string location_name, const std::string addres, int capacity);

    // System check that location is available on desired DATE
    bool is_Available(const std::string& date) const;
    void ReserveEvent(Event* event);

    bool check_isAvailable();

    // Getters
    // method to get location
    std::string getLocationName() const;

    std::string getAddress() const;
    int getCapacity() const;

    void DisplayReservedEvents_array();

    // just for testing
    void setLocationName(const std::string name);


};
#endif // LOCATION_H

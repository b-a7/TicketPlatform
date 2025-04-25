#include "artist.h"
#include "platform.h"
#include "location.h"

class Artist;
class Location;

// check if artists can access public methods

class Event {
    friend class Artist;

private:
    // points to Artist object with name, style, description
    Artist* artist;
    Location* location;

    // //alternative just providing artist and location to event as strings
    // std::string artist;
    // std::string location;

    std::string date;
    double price;
    bool isVIP;
    int available_tickets;
    std::string event_name;

public:
    Event(Artist* artist, Location* location, const std::string& date, double price,
          bool isVIP, int available_tickets);

    const std::string getDate() const;
    const std::string getLocation() const;

    double getPrice() const;
    bool getVIPStatus() const;
    int getAvailableTickets() const;

    std::string getEventName() const;

    // set
    //void setLocation(const std::string new_location);

    void setEventLocation(const std::string new_location, Platform& platform);

    void setDate(const std::string new_date);

    void setPrice(double price);

    void setAvailableTickets(int tickets_available);

    static std::vector<Event*> event_list; // Declare static member here

};




// #ifndef EVENT_H
// #define EVENT_H

// #include "artist.h"

// class Artist;
// class Location;

// // check if artists can access public methods

// class Event {
// private:
//     // points to Artist object with name, style, description
//     Artist* artist;
//     Location* location;

//     std::string date;
//     double price;
//     bool isVIP;
//     int available_tickets;

// public:
//     Event(Artist* artist, Location* location, const std::string& date, double price,
//           bool isVIP, int available_tickets);

// protected:
//     // member variable reserved_events is a vector containing pointers to Event* objects
//     static std::vector<Event*> event_list;
// };

// #endif // EVENT_H






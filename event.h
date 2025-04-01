#include "artist.h"

class Artist;
class Location;

// check if artists can access public methods

class Event {
private:
    // points to Artist object with name, style, description
    Artist* artist;
    Location* location;

    std::string date;
    double price;
    bool isVIP;
    int available_tickets;
    std::string event_name;

public:
    Event(Artist* artist, Location* location, const std::string& date, double price,
          bool isVIP, int available_tickets);

    std::string getDate() const;
    double getPrice() const;
    bool getVIPStatus() const;
    int getAvailableTickets() const;
    std::string getEventName() const;
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






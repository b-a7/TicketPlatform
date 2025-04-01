#ifndef ARTIST_H
#define ARTIST_H

#include "user.h"

class Event;

class Artist : public User {
private:
    std::string name;
    std::string style;
    std::string description;

    // List of upcoming events ( vector of Event type )
    std::vector<Event*> upcoming_events;


public:
    // Empty constructor
    Artist();

    // Constructor
    Artist(const std::string& username, const std::string& password,
           const std::string& name, const std::string& style,
           const std::string& description);

    string getType() const override {return "Artist";}

    void addEvent(Event& event);

    // Event management -- assumes event ID or some way of identifying events
    void createEvent(Event* event);
    void modifyEvent(Event* event);
    void deleteEvent(Event* event);

    // Artist update to their own profile
    void updateDescription(const std::string& new_description);
    void updateStyle(const std::string new_style);

    //void displayInfo() const;

    const std::string Artist::createArtist(const std::string& username, const std::string& password,
                                      const std::string& name, const std::string& style,
                                      const std::string& description);
    const std::string defineArtistName();
    const std::string defineArtistStyle();
    const std::string defineArtistBio();


};


#endif // ARTIST_H

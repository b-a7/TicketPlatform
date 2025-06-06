#ifndef ARTIST_H
#define ARTIST_H

#include "user.h"
#include "platform.h"

class Event;
class Administrator;

class Artist : public User {
    friend class Administrator;
    friend class Event;


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

    //std::string getType() const override {return "Artist";}

    void addEvent(Event& event);

    void deleteEvent(Event& event);

    //void displayInfo();

    // Event management -- assumes event ID or some way of identifying events
    void createEvent(Platform& platform);
    void modifyEvent(Event* event, Platform& platform);


    // Artist update to their own profile
    void updateDescription(const std::string& new_description);
    void updateStyle(const std::string new_style);
    void updateName(const std::string new_name);

    //void displayInfo() const;

    void createArtist(Platform& platform);

    const std::string defineArtistName();
    const std::string defineArtistStyle();
    const std::string defineArtistBio();

    std::string getName();

    std::string getType() const override { return "Artist"; }

    std::string getStyle();

    std::string getDescription() { return description; }

    void artistDashboard(Platform& platform);

    void updateFeatures(Platform& platform);



};


#endif // ARTIST_H

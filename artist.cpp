#include "artist.h"
#include "event.h"
#include "location.h"

using namespace std;

class Event;

vector<Event*> upcoming_events;

// receives reference to user object and adds this to current list
void Artist::addEvent(Event& event) {

    upcoming_events.push_back(&event);    // need to give address as the vector holds pointers to Events, not objects themselves

}

void Artist::deleteEvent(Event& event) {

    // find events by name and date
    string find_date, find_location;

    cout << "Where is the location of the event you want to delete? ";
    getline(cin, find_location);

    cout << "What is the date of the event you want to delete? (DD/MM/YYYY) ";
    getline(cin, find_date);

    bool found = false;

    for (size_t i = 0; i < upcoming_events.size(); i++) {
        if ((upcoming_events[i]->getLocation() == find_location) && (upcoming_events[i]->getDate() ==  find_date)) {
            upcoming_events.erase(upcoming_events.begin() + i);
            found = true;
            cout << "Event deleted successfully." << endl;
            break;
        }
    }
    // **** found condition not being used
}


// using initialiser list instead of 'this->name' format
Artist::Artist(const string& username, const string& password,
            const string& name, const string& style,
            const string& description)
    : User(username, password),
      name(name),
      style(style),
      description(description)
{}

void Artist::displayInfo() {
    cout << "Artist: " << name << endl;
    cout << "Style: " << style << endl;
    cout << "Description: " << description << endl;
}

void Artist::updateDescription(const string& new_description) {
    this->description = new_description;
}

void Artist::updateStyle(const string new_style) {
    this->style = new_style;
}

void Artist::createEvent(Event* event) {

    // needs to ask user for input, storing in temporary variables, and then fill in Event constructor with this information
        // then the Event constructed has to be added to the end of the event* vector

    // temporary variables

    string artist, date, location;
    double ticket_price;
    int isEventVIP_temp;
    bool isEventVIP;
    int available_tix;

    // need to ask artist for input to fill out for events and store in temporary variables

    cout << "Enter event artist: ";
    getline(cin, artist);       // this is only giving an artist name not the artist object to the event class created

    cout << "Enter event location: ";
    getline(cin, location);

    // check location function *****

    //get event details above

    cout << "Enter event date (format DD/MM/YYYY): ";
    getline(cin, date);

    cout << "Set Ticket Price: ";
    cin >> ticket_price;

    cout << "Set available tickets: ";
    cin >> available_tix;

    cout << "Is the event VIP only (Y / N): " ;
    cin >> isEventVIP_temp;
    if (isEventVIP_temp == 'Y') {
        isEventVIP = true;
    }
    else {
        false;
    }

    // need to pass actual artist ****** FIX
    Event* event_temp = new Event(artist, location, date, ticket_price, isEventVIP, available_tix);

    // need to add event to event_list
    addEvent(*event_temp);

}


// creates user of type artist using constructor
const string Artist::createArtist(const string& username, const string& password,
                                  const string& name, const string& style,
                                  const string& description) {

    User* artist = new Artist(username, password, name, style, description);

    addUser(*artist);

    cout << "User of type ARTIST created" << endl;

}

// functions below are for creating 'defining' artist properties
const string Artist::defineArtistName() {

    string name;
    cout << "Enter Artist name: " << endl;

    // using getline to allow for multi-word input
    getline(cin, name);

    return name;
}

const string Artist::defineArtistStyle() {

    string style;

    cout << "Enter Artist style: " << endl;

    // Use getline to allow for multi-word input
    getline(cin, style);

    return style;

}

const string Artist::defineArtistBio() {

    string bio;

    cout << "Enter Artist description: " << endl;

    // Use getline to allow for up to '\n', multi-line too
    getline(cin, bio);

    return bio;

}

void Artist::modifyEvent(Event* event) {

    // can modify: location, date, price, isVIP, available_tickets

    int option;

    cout << "What aspect of the event do you want to manage: " << endl;
    cout << "   1)   Location " << endl;
    cout << "   2)   Date " << endl;
    cout << "   3)   Price" << endl;
    cout << "   4)   If the event is VIP exclusive " << endl;
    cout << "   5)   Number of available tickets" << endl;
    cout << "Enter selection (1-5): ";


    switch(option) {
        case 1: {
        string new_location;
        cout << "Enter new location of the event: " << endl;
        getline(cin, new_location);

        event->setLocation(new_location);
        }

        case 2: {
            string new_date;
            cout << "Enter new date of the event: " << endl;


        }
        case 3: {

            double new_price;
            cout << "Enter new ticket price: " << endl;

        }
        case 4: {
            bool VIP_change;
            cout << "Is the event now VIP only? " << endl;

        }
        case 5: {
            int new_tix_available;
            cout << "Change number of available tickets to: " << endl;
            cin >> new_tix_available;
            // update tix availabel function like set_tix available called on specific event
        }

    }


    return;
}

// get/set location
// get/set date

// ///////// from header ////////////////////
// class Event;

// class Artist : public User {
// private:
//     std::string name;
//     std::string style;
//     std::string description;

//     // List of upcoming events ( vector of Event type )
//     std::vector<Event*> upcoming_events;

// public:
//     // Empty constructor
//     Artist();

//     // Constructor
//     Artist(const std::string& username, const std::string& password,
//            const std::string& name, const std::string& style,
//            const std::string& description);

//     // Event management -- assumes event ID or some way of identifying events
//     void createEvent(Event* event);
//     void modifyEvent(Event* event);


//     void deleteEvent(Event* event);

//     // Artist update to their own profile
//     void updateDescription(const std::string& new_description);

//     void updateStyle(const std::string new_style);
// };

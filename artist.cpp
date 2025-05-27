#include "artist.h"
#include "event.h"
#include "location.h"
#include "platform.h"

#include <stdexcept>

using namespace std;

vector<Event*> upcoming_events;

Artist::Artist() {}

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

    //bool found = false;

    for (size_t i = 0; i < upcoming_events.size(); i++) {
        if ((upcoming_events[i]->getLocation() == find_location) && (upcoming_events[i]->getDate() ==  find_date)) {
            upcoming_events.erase(upcoming_events.begin() + i);
            //found = true;
            cout << "Event deleted successfully." << endl;
            break;
        }
        else {
            cout << "Event not found! " << endl;
        }
    }

    // **** found condition not being used
}

// options to delete event by: location, date
// comparing location name as string to location pointer: inside location pointer there should still be a location name


// using initialiser list instead of 'this->name' format
Artist::Artist(const string& username, const string& password,
            const string& name, const string& style,
            const string& description)
    : User(username, password),
      name(name),
      style(style),
      description(description)
{}

// void Artist::displayInfo() {
//     cout << "Artist: " << name << endl;
//     cout << "Style: " << style << endl;
//     cout << "Description: " << description << endl;
// }

void Artist::updateDescription(const string& new_description) {
    this->description = new_description;
}

void Artist::updateStyle(const string new_style) {
    this->style = new_style;
}

void Artist::updateName(const std::string new_name) {
    this->name = new_name;
}

void Artist::createEvent(Platform& platform) {

    // needs to ask user for input, storing in temporary variables, and then fill in Event constructor with this information
        // then the Event constructed has to be added to the end of the event* vector

    // temporary variables

    string artist_finder, date, location_finder;
    double ticket_price;
    int isEventVIP_temp;
    bool isEventVIP;
    int available_tix;

    // need to ask artist for input to fill out for events and store in temporary variables

    cout << "Enter event artist: ";
    getline(cin, artist_finder);       // this is only giving an artist name not the artist object to the event class created

    // conditional is like if-else, if artist_finder.empty(), pointer = this, else pointer = pointer from findArtistByName
    Artist *artist_temp = artist_finder.empty() ? this : platform.findArtistByName(artist_finder);
    if (!artist_temp) throw std::invalid_argument("Artist not found");

    cout << "Enter event location: ";
    getline(cin, location_finder);

    Location *location = location_finder.empty() ? nullptr : platform.findLocationByName(location_finder);
    if (!location) throw std::invalid_argument("Location not found");

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

    // need to search if artist exists, if not give error
        // if artist exists in user search, pass object to event constructor below

    // need to pass actual artist ****** FIX -- is it better to pass artist / location pointer or just strings is fine
    Event* event_temp = new Event(artist_temp, location, date, ticket_price, isEventVIP, available_tix);

    // need to add event to event_list
    addEvent(*event_temp);

}


// actual string constructor
//Event(Artist* artist, Location* location, const std::string& date, double price,
//    bool isVIP, int available_tickets)
//

// creates user of type artist using constructor
void Artist::createArtist(Platform& platform) {

    string username, password;
    cout << "Enter username: ";
    cin >>  username;

    cout << "Enter password: ";
    cin >> password;

    string name = defineArtistName();
    string style = defineArtistStyle();
    string description = defineArtistBio();

    User* artist = new Artist(username, password, name, style, description);

    platform.addUser(artist);

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

void Artist::modifyEvent(Event* event, Platform& platform) {

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

        event->setEventLocation(new_location, platform);
        // location is a pointer to an actual location object that holds properties address, isavailable ... etc.

        }

        case 2: {
            string new_date;
            cout << "Enter new date of the event: " << endl;
            getline(cin, new_date);
            event->setDate(new_date);

        }
        case 3: {

            double new_price;
            cout << "Enter new ticket price: " << endl;
            cin >> new_price;
            event->setPrice(new_price);

        }
        case 4: {
            bool VIP_change;
            cout << "Is the event now VIP only? (Y / N)" << endl;
            // function to check input and then set if VIP or not

        }
        case 5: {
            int new_tix_available;
            cout << "Change number of available tickets to: " << endl;
            cin >> new_tix_available;
            event->setAvailableTickets(new_tix_available);
            // update tix availabel function like set_tix available called on specific event
        }

    }

    return;
}

string Artist::getName() {
    return this->name;
}

string Artist::getStyle() {
    return this->style;
}

void Artist::updateFeatures(Platform& platform) {

    bool done = false;

    while (!done) {

        cout << "\n*************************" << endl;
        cout << "Update Artist Features Menu -- select an option: " << endl;
        cout << "*************************" << endl;
        cout << "   1)   Update Name" << endl;
        cout << "   2)   Update Style" << endl;
        cout << "   3)   Update Description" << endl;

        cout << " \n  (0)   Return Back" << endl;
        cout << "*************************" << endl;
        cout << "Enter selection (0-3)): ";

        int choice;
        cin >> choice;

        if (cin.fail()) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid input. Please enter a number.\n";
            continue;
        }

        if (choice == 1) {
            string new_name;
            cout << "\nEnter new name: ";
            cin >> new_name;
            this->updateName(new_name);
            cout << "\nName successfully updated" << endl;

        }
        else if (choice == 2) {
            string new_style;
            cout << "\nEnter new style: ";
            cin >> new_style;
            this->updateName(new_style);
            cout << "\nStyle successfully updated" << endl;

        }
        else if (choice == 3) {
            string new_description;
            cout << "\nEnter new description: ";
            cin >> new_description;
            this->updateName(new_description);
            cout << "\nDescription successfully updated" << endl;

        }
        else if (choice == 0) {
            break;
        }

        else {
            cout << "Invalid input! Enter selection (0-4)" << endl;
        }

    }
}

void Artist::artistDashboard(Platform& platform) {

    bool done = false;

    while (!done) {

        cout << "\n--------------------------" << endl;
        cout << "Artist Menu -- select an option: " << endl;
        cout << "--------------------------" << endl;
        cout << "   1)   Create Event" << endl;
        cout << "   2)   Modify Event" << endl;
        cout << "   3)   Delete Event" << endl;
        cout << "   4)   Update Features" << endl;


        cout << " \n  (0)   Return Back" << endl;
        cout << "--------------------------" << endl;
        cout << "Enter selection (0-4)): ";

        int choice;
        cin >> choice;

        if (cin.fail()) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid input. Please enter a number.\n";
            continue;
        }

        if (choice == 1) {
            createEvent(platform);
        }

        else if (choice == 2) {
            //***to do

            //modifyEvent(platform);
        }

        else if (choice == 3) {
            //***to do

        }

        else if (choice == 4) {
            updateFeatures(platform);
        }

        else if (choice == 0) {
            break;
        }

        else {
            cout << "Invalid input! Enter selection (0-4)" << endl;
        }

    }


}




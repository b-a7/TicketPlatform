#ifndef PLATFORM_H
#define PLATFORM_H
#include <vector>
#include <string>

class User;
class Artist;
class Location;

class Platform {
private:
    std::vector<User*> user_list;
    std::vector<Location*> locations;

public:
    Platform();
    ~Platform();

    void addUser(User *user);
    int getNumUsers() const;
    Artist* findArtistByName(const std::string& name);
    Location* findLocationByName(const std::string& name);
    void run();

    void displayUsers();

    void displayAvailableLocations();

    // what is availabe location? -- location at a set date is free
    // check if at certain date the location isavailable

};


#endif // PLATFORM_H









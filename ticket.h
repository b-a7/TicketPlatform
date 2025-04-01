#ifndef TICKET_H
#define TICKET_H

class Event;
class Attendee;

class Ticket {
private:
    Event* event;
    Attendee* owner;      // Current owner (Attendee or VIPAttendee)
    double price;         // Price of the ticket (can change in secondary market)

public:
    Ticket(Event* event, Attendee* owner, double price);

    // Getters
    Event* getEvent() const;
    Attendee* getOwner() const;
    double getPrice() const;

    // Setters
    void setOwner(Attendee* newOwner);
    void setPrice(double newPrice);


#endif // TICKET_H

To do:

Artist:

[1] Implementation of the required functionality in each class to 
display the users, events, and locations available in the program (using polymorphism
so that regular attendees can only see non-VIP events, while VIP attendees can see all events)

[ ] display users, 
[ ] display events
[ ] display locations available

[2] modifyEvent(), method implementation

[3] to delete events: we need artist to give name, date

Administrator:

Event:

**    Changes:
**    - added setLocation
**    - changed event constructor to make paramaters not pointers to artists
        but just artist name as string

Questions:
- should setLocation be in event or under artist

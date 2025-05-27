To do:

NEW:
- need to manage events and figure this all out within artist
- View ticket, buy ticket, all attendee actions
- when new user created they need to be directed to dashboard screens



Artist:

*[ ]* add event list to each artist

[1] Implementation of the required functionality in each class to 
display the users, events, and locations available in the program (using polymorphism
so that regular attendees can only see non-VIP events, while VIP attendees can see all events)

[ ] display users, 
[ ] display events
[ ] display locations available

[ ] modifyEvent(), method implementation

[ ] to delete events: we need artist to give name, date

Administrator:

[ ] modify_user method
[ ] delete_user method

Event:

**    Changes:
**    - added setLocation
**    - changed event constructor to make paramaters not pointers to artists
        but just artist name as string

Questions:
- should setLocation be in event or under artist

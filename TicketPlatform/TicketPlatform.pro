TEMPLATE = app
CONFIG += console c++17
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
        SecondaryMarket.cpp \
        VIP_Attendee.cpp \
        administrator.cpp \
        artist.cpp \
        attendee.cpp \
        event.cpp \
        location.cpp \
        main.cpp \
        ticket.cpp \
        user.cpp

HEADERS += \
    SecondaryMarket.h \
    VIP_Attendee.h \
    administrator.h \
    artist.h \
    attendee.h \
    event.h \
    location.h \
    platform.h \
    ticket.h \
    user.h

DISTFILES += \
    README.md

/*
    TINSIM01-deelopdracht2.cpp

    version 2 (final version)

    CMI-TI 22 TINSIM01
    Student: Thijs Dregmans (1024272)
    Simulation and Modeling deelopdracht 2
    Last edited: 29-10-2022

*/

#include <iostream>
#include <algorithm>

#pragma once
using namespace std;

class event {
public:
    // Construct sets time of event.
    event(unsigned int t) : time(t)
    { }

    // Execute event my invoking this method.
    virtual void processEvent() = 0;
    bool operator> (const event* evt_) {
        return time > evt_->time;
    }

    const unsigned int time;
};
/*The simulation queue needs to maintain a collection of different types of events,
sometimes called a heterogeneous collection.
Each different form of event is represented by a subclass of class event,
but not all events have the same exact type.
For this reason the collection must store pointers to events,
instead of the events themselves.*/

typedef std::greater<event*> eventComparator;

class bagageReadyEvent : public event {
public:
    bagageReadyEvent(unsigned int time)
        : event(time) { }
    virtual void processEvent();
private:
};

// returns a random integer between 0 and n with n <= 32767 <= INT_MAX
inline int irand(int n)
{
    static int seq[] = {
        0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 0xa, 0xb, 0xc, 0xd, 0xe, 0xf
    };

    std::random_shuffle(seq, seq + sizeof seq / sizeof * seq);

    const int rnd = (seq[0] << 11) | (seq[1] << 8) | (seq[2] << 4) + seq[3];

    return rnd % n;
}

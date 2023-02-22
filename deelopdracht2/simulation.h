/*
    TINSIM01-deelopdracht2.cpp

    version 2 (final version)

    CMI-TI 22 TINSIM01
    Student: Thijs Dregmans (1024272)
    Simulation and Modeling deelopdracht 2
    Last edited: 29-10-2022

*/

#include <vector>
#include <iostream>
#include <queue>

#include "event.h"

using namespace std;

// Framework for discrete event-driven simulations.
class simulation {
public:
    simulation() : time(0), eventQueue()
    {}
    void run();
    void  scheduleEvent(event* newEvent) {
        eventQueue.push(newEvent);
    }
    unsigned int time;
protected:
    std::priority_queue<event*,
        std::vector<event*, std::allocator<event*> >,
        eventComparator > eventQueue;
};

/*The simulation is based around a subclass of class simulation,
defined as follows*/

static class theBagageMover3000 : public simulation {
public:
    theBagageMover3000() : simulation(), free(true)
    { }
    bool available();
    // Data fields.
    bool free;
} theSimulation;

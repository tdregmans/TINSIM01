/*
    TINSIM01-deelopdracht2.cpp

    version 2 (final version)

    CMI-TI 22 TINSIM01
    Student: Thijs Dregmans (1024272)
    Simulation and Modeling deelopdracht 2
    Last edited: 29-10-2022

*/

#include <iostream>
#include "simulation.h"

void simulation::run() {

    while (!eventQueue.empty()) {

        event* nextEvent = eventQueue.top();
        eventQueue.pop();
        time = nextEvent->time;
        nextEvent->processEvent();
        
        delete nextEvent;
    }
}

// If BM3000 is free, return true
bool theBagageMover3000::available() {

    if (free) {
        std::cout << "Bagage Mover 3000 is free.\n";
        return true;
    }
    else {
        std::cout << "Bagage Mover 3000 is not free.\n";
        return false;
    }
}

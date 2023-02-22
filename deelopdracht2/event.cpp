/*
    TINSIM01-deelopdracht2.cpp

    version 2 (final version)

    CMI-TI 22 TINSIM01
    Student: Thijs Dregmans (1024272)
    Simulation and Modeling deelopdracht 2
    Last edited: 29-10-2022

*/

#include "event.h"
#include "simulation.h"

#ifdef _WIN32
#include <Windows.h>
#else
#include <unistd.h>
#endif


void bagageReadyEvent::processEvent() {
    std::cout << "Bagage is ready.\n";
    if (theSimulation.available()) {
        std::cout << "Bagage Mover 3000 picked up bagage.\n";
        Sleep(500); // delivering bagage takes the BM3000 500ms
        std::cout << "Bagage Mover 3000 delivered bagage.\n";
        
    }
}

/*
    TINSIM01-deelopdracht2.cpp

    version 2 (final version)
    
    CMI-TI 22 TINSIM01
    Student: Thijs Dregmans (1024272)
    Simulation and Modeling deelopdracht 2
    Last edited: 29-10-2022

    Requirements
        -   The Program Simulates the model of the Bagage Mover 3000.

    Tests
        Tests are done with the output of the program, using the Command Line.

    Design
        The Bagage Mover 3000 simulation is an event-based simulation.
        At the start of the program, are a number of bagage items loaded.
        The Bagage Mover 3000 wait till an bagage item presents itself.
        When one does, the BM3000 picks it up and moves it to the right location.
        Then the BM3000 continues to wait till an new bagage item needs to be moved.
*/

#include <iostream>
#include "simulation.h"

int main() {

    std::cout << "The Bagage Mover 3000 simulation \n";

    // Load queue with some number of initial events.
    for (unsigned t = 0; t < 20; t += irand(6)) {

        std::cout << "pumping queue with event " << t << '\n';
        theSimulation.scheduleEvent(new bagageReadyEvent(t));
    }

    // Run the simulation.
    theSimulation.run();

    std::cout << "\nEnd of simulation\n";

    return 0;
}

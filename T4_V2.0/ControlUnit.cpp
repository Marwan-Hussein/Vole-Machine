#include <iostream>
#include "ControlUnit.h"

using namespace std;

ControlUnit::ControlUnit(CPU *c, Memory *m) : cpu(c), memory(m) {}

void ControlUnit::fetchExecuteCycle()
{
    cout << "Starting fetch-execute cycle...\n";
    while (true)
    {
        string instruction = cpu->fetchInstruction();
        if (instruction == "HALT")
        {
            break;
        }
        cpu->executeNextInstruction();
        cpu->displayState();

        // Step-by-step execution control
        string cont;
        cout << "Press Enter to continue or 'q' to quit: ";
        getline(cin, cont);
        if (cont == "q")
            break;
    }
    cout << "Program completed.\n";
}

void ControlUnit::reset()
{
    cpu->setProgramCounter(0);
}
#include <iostream>
#include <string>
#include <fstream>
// #include "CPU.h"
// #include "Memory.h"
#include "Machine.h"

using namespace std;

void Machine::loadProgramFile(string &fileName)
{
    ifstream f(fileName);
    while (!f.good())
    {
        cout << "not existing file please input again: ";
        cin >> fileName;
        ifstream f(fileName);
        if (f.good())
            break;
    }
    cout << "Loading program from file " << fileName << " ....\n";
}

void Machine::outputState() const
{
    cout << "Machine State:\n";
    // processor.displayState(); // from cpu
    // memory.displayState();    // from memory
}

void Machine::runStepByStep()
{
    cout << "Running program step-by-step.\n";

    /*while (processor.executeNextInstruction(memory) /*from memory)
    {
        outputState();
        cout << "Press Enter to continue to the next step: \n";
        cin.ignore(); // continue inputting until press enter
    }*/
}

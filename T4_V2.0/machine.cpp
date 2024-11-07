#include <iostream>
#include <string>
#include <fstream>
#include "CPU.h"
#include "Memory.h"
#include "Machine.h"
#include "MainUI.h"
using namespace std;

Machine::Machine() : processor(&memory) {}
void Machine::loadProgramFile(string &fileName)
{
    MainUI mainui;
    ifstream f(fileName);
    while (!f.good())
    {
        cout << "not existing file please input again: ";
        cin >> fileName;
        f.open(fileName);
    }

    if (!mainui.isvalid_fileINstructions(fileName))
    {
        f.close();
        cout << "Invalid instructions in this file please input a correct instructions file.\n";
        mainui.inputFileName();
        return;
    }
    cout << fileName << " loaded successfully.\n";
    int address = 0;
    string line;
    while (getline(f, line))
        memory.setcell(address++, line);
    f.close();
}

void Machine::outputState() const
{
    Memory memory;
    cout << "Machine State:\n";
    processor.displayState(); // from cpu
    cout << '\n';
    memory.displayState(); // from memory
    registers.displayState();
    cout << "----------------\n";
}

void Machine::runStepByStep()
{
    cout << "\nRunning program step-by-step.\n";

    while (processor.getProgramCounter() != -2)
    { // Check for HALT (-2)
        processor.fetchInstruction();
        processor.executeNextInstruction();
        outputState();
        cout << "Press Enter to continue to the next step: \n";
        cin.ignore();
    }
    cout << "Execution completed.\n";
}
void Machine::run()
{
    while (processor.getProgramCounter() != -2)
    { // Check for HALT (-2)
        processor.fetchInstruction();
        processor.executeNextInstruction();
    }
}

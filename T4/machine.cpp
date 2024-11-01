#include <iostream>
#include <fstream>
#include <string>
#include "Machine.h"
#include "CPU.h"
#include "Memory.h"

using namespace std;

Machine::Machine() : cpu(&memory), controlUnit(&cpu, &memory) {}

void Machine::loadProgramFile(const string &fileName) {
    ifstream file(fileName);
    if (!file) {
        cerr << "Error: Cannot open file " << fileName << endl;
        return;
    }
   
    string line;
    int address = 0;
    while (getline(file, line)) {
        memory.setcell(address++, line);
    }
    cout << "Program loaded from file " << fileName << "\n";
}

void Machine::outputState() const {
    cout << "Machine State:\n";
    cpu.displayState();
}

void Machine::runStepByStep() {
    cout << "Running program step-by-step.\n";
    controlUnit.fetchExecuteCycle();
}

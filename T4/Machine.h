#ifndef MACHINE_H
#define MACHINE_H

#include <string>
// #include "CPU.h"
// #include "Memory.h"
using namespace std;

class Machine
{
    // private:
    // CPU processor;
    // Memory memory;

public:
    Machine() = default;
    ~Machine() = default;
    void loadProgramFile(string &fileName);
    void outputState() const;
    void runStepByStep();
};

#endif // MACHINE_H

#ifndef MACHINE_H
#define MACHINE_H

#include <string>
#include "CPU.h"
#include "Memory.h"
using namespace std;

class Machine
{
private:
    CPU processor;
    Memory memory;
    Register registers;

public:
    Machine();
    ~Machine() = default;
    void loadProgramFile(string &fileName);
    void outputState() const;
    void runStepByStep();
    void run();
};

#endif // MACHINE_H

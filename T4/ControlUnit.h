#ifndef CONTROLUNIT_H
#define CONTROLUNIT_H

#include "CPU.h"
#include "Memory.h"

class ControlUnit {
private:
    CPU* cpu;
    Memory* memory;

public:
    ControlUnit(CPU* c, Memory* m);
    ~ControlUnit() = default;

    void fetchExecuteCycle(); 
    void reset();
};

#endif // CONTROLUNIT_H

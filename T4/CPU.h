#ifndef CPU_H
#define CPU_H

#include <string>
#include "Register.h"
#include "Memory.h"

class ControlUnit; 

class CPU {
private:
    Register registers;
    Memory* memory;
    int programCounter = 0; 
    std::string instructionRegister;

public:
    CPU(Memory* mem);
    ~CPU() = default;
    
    void executeNextInstruction(); 
    void setProgramCounter(int pc);
    int getProgramCounter() const;
    std::string fetchInstruction(); 
    void displayState() const;
};

#endif // CPU_H

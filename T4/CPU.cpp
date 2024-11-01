#include "CPU.h"
#include <iostream>

using namespace std;

CPU::CPU(Memory* mem) : memory(mem) {}

void CPU::setProgramCounter(int pc) {
    programCounter = pc;
}

int CPU::getProgramCounter() const {
    return programCounter;
}

string CPU::fetchInstruction() {
    instructionRegister = memory->getcell(programCounter);
    programCounter++;
    return instructionRegister;
}

void CPU::executeNextInstruction() {

    string instruction = instructionRegister;

    if (instruction.substr(0, 3) == "MOV") {
        int reg = instruction[4] - '0'; 
        string value = instruction.substr(6);
        registers.setcell(reg, value);
    } 
    else if (instruction.substr(0, 3) == "ADD") {
        int reg1 = instruction[4] - '0';
        int reg2 = instruction[6] - '0';
        int result = stoi(registers.getcell(reg1)) + stoi(registers.getcell(reg2));
        registers.setcell(reg1, to_string(result));
    } 
    else if (instruction.substr(0, 3) == "SUB") {
        int reg1 = instruction[4] - '0';
        int reg2 = instruction[6] - '0';
        int result = stoi(registers.getcell(reg1)) - stoi(registers.getcell(reg2));
        registers.setcell(reg1, to_string(result));
    } 
    else if (instruction.substr(0, 3) == "JMP") {
        int address = stoi(instruction.substr(4));
        setProgramCounter(address);
    }
    // Additional instructions like LOAD, STORE, etc. would be implemented here
}

void CPU::displayState() const {
    cout << "CPU State:\n";
    cout << "Program Counter: " << programCounter << "\n";
    cout << "Instruction Register: " << instructionRegister << "\n";
    // Display additional register or memory information as needed
}

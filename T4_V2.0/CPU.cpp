#include "CPU.h"
#include "ALU.h"
#include <iostream>

using namespace std;

CPU::CPU(Memory *mem) : memory(mem) {}

void CPU::setProgramCounter(int pc)
{
    programCounter = pc;
}

int CPU::getProgramCounter() const
{
    return programCounter;
}

string CPU::fetchInstruction()
{
    instructionRegister = memory->getcell(programCounter / 2);
    programCounter += 2;
    return instructionRegister;
}

void CPU::executeNextInstruction()
{

    string instruction = instructionRegister;
    char opcode = instruction[0];
    int reg, address, reg2, reg3;
    string hex1, hex2;
    string content_of_memory;
    ALU alu;
    // cout << "Executing instruction: " << instruction << "\n"; // Debug line
    switch (opcode)
    {
    case '1': // 15A7 ==> R5 = mem(A7)
        reg = alu.hextodecimal(instruction.substr(1, 1));
        registers.setcell(reg, memory->getcell(alu.hextodecimal(instruction.substr(2, 2))));
        break;

    case '2': // 25A7 ==> R5 = A7
        reg = alu.hextodecimal(instruction.substr(1, 1));
        registers.setcell(reg, instruction.substr(2, 2));
        break;

    case '3': // 35A7 ==> mem(A7) = R5
        reg = alu.hextodecimal(instruction.substr(1, 1));
        address = alu.hextodecimal(instruction.substr(2, 2));
        memory->setcell(address, registers.getcell(reg));
        break;

    case '4':                                              // 40A7 ==> RA = R7
        reg = alu.hextodecimal(instruction.substr(2, 1));  // A
        reg2 = alu.hextodecimal(instruction.substr(3, 1)); // 7
        registers.setcell(reg, registers.getcell(reg2));
        break;

    case '5': // 5547 ==> R5 = R4 + R7
        reg = alu.hextodecimal(instruction.substr(2, 1));
        hex1 = registers.getcell(reg);
        reg2 = alu.hextodecimal(instruction.substr(3, 1));
        reg3 = alu.hextodecimal(instruction.substr(3, 1));
        hex2 = registers.getcell(reg2);
        registers.setcell(reg3, alu.add(hex1, hex2));
        break;

    case '6':
        reg = alu.hextodecimal(instruction.substr(2, 1));
        hex1 = registers.getcell(reg);
        reg2 = alu.hextodecimal(instruction.substr(3, 1));
        reg3 = alu.hextodecimal(instruction.substr(3, 1));
        hex2 = registers.getcell(reg2);
        registers.setcell(reg3, alu.add_float(hex1, hex2));
        break;

    case 'B': // B5A7==> (R5 = R0? jump to mem(A7))
        reg = alu.hextodecimal(instruction.substr(1, 1));
        content_of_memory = memory->getcell(alu.hextodecimal(instruction.substr(2, 2)));
        address = alu.hextodecimal(content_of_memory);
        if (registers.getcell(reg) == registers.getcell(0))
        {
            setProgramCounter(address);
            // jump to the instruction line (address/2) in f
        }
        break;

    case 'C':
        cout << "HALT: Execution terminated.\n";
        setProgramCounter(-2);
        return;
    }
    // Additional instructions like LOAD, STORE, etc. would be implemented here
}

void CPU::displayState() const
{
    cout << "CPU State:\n";
    cout << "Program Counter: " << programCounter;
    cout << "\t|\tInstruction Register: " << instructionRegister << "\n";
    // Display additional register or memory information as needed
}

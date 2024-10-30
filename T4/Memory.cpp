#include <vector>
#include <string>
#include "Memory.h"
using namespace std;

Memory::Memory() {
    memory.resize(256);
}

void Memory::setcell(int address, const string& val) {
    if (address >= 0 && address < 256) {
        memory[address] = val;
    } 
}

string Memory::getcell(int address) const {
    return (address >= 0 && address < 256) ? memory[address] : "00";
}

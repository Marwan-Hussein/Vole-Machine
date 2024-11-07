#include <vector>
#include <string>
#include <iostream>
#include <iomanip>
#include "Memory.h"
using namespace std;

Memory::Memory()
{
    memory.resize(256);
}

void Memory::setcell(int address, const string &val)
{
    /*if (address == 0)
        cout << "output to screen: " << val << '\n';*/
    if (address >= 0 && address < 256)
    {
        memory[address] = val;
    }
}

string Memory::getcell(int address) const
{
    return (address >= 0 && address < 256) ? memory[address] : "0A";
}

void Memory::displayState() const
{
    cout << "Memory State:\n";
    for (int i = 0; i < memory.size(); ++i)
    {
        if (!memory[i].empty())
        {
            cout << "Address " << setw(2) << setfill('0') << hex << uppercase << i << ": " << memory[i] << '\n';
        }
    }
    cout << dec;
}
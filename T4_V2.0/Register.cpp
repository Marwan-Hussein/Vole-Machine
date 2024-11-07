#include "Register.h"
#include <iostream>
#include <iomanip>
using namespace std;
Register::Register()
{
    reggister.resize(16);
}
void Register::setcell(int address, const string &val)
{
    if (address >= 0 && address < 16)
    {
        reggister[address] = val;
    }
}
string Register::getcell(int address) const
{
    return address >= 0 && address < 16 ? reggister[address] : "00";
}

void Register::displayState() const
{
    cout << "Memory State:\n";
    for (int i = 0; i < reggister.size(); ++i)
    {
        if (!reggister[i].empty())
        {
            cout << "Address " << setw(2) << setfill('0') << hex << uppercase << i << ": " << reggister[i] << '\n';
        }
    }
    cout << dec;
}
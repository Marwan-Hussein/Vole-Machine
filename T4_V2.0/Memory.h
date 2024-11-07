#ifndef MEMORY_H
#define MEMORY_H
#include <iostream>
#include <vector>
using namespace std;

class Memory
{
private:
    vector<string> memory;

public:
    Memory();
    void setcell(int address, const string &val);
    string getcell(int address) const;
    void displayState() const;
    ~Memory() = default;
};
#endif // MEMORY_H
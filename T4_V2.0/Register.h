#include <vector>
#include <string>
#ifndef REGISTER_H
#define REGISTER_H
using namespace std;

class Register
{
private:
    vector<string> reggister;

public:
    Register();
    void setcell(int address, const string &val);
    string getcell(int address) const;
    void displayState() const;
};

#endif // REGISTER_H
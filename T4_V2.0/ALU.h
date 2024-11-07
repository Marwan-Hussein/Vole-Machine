#ifndef ALU_H
#define ALU_H
#include <string>
using namespace std;

class ALU
{
public:
    ALU() = default;
    ~ALU() = default;

    int hextodecimal(string hexValue);
    float hextofloat(string hexValue);
    string add(string hex1, string hex2);
    string floattobin(float decimalValue);
    string decimaltohex(int decimalValue);
    string binToHexa(string bin);
    string add_float(string h1, string h2);
    string bitwiseXOR(string hex1, string hex2);
};

#endif // ALU_H

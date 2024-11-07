#include "ALU.h"
#include <bits/stdc++.h>

using namespace std;

int ALU::hextodecimal(string hexValue)
{
    int decimalValue;
    decimalValue = stoi(hexValue, nullptr, 16);
    return decimalValue;
}

string ALU::floattobin(float fVal)
{
    int sign = fVal < 0 ? 1 : 0;
    if (fVal < -7.5)
        fVal = -7.5;
    if (fVal > 7.5)
        fVal = 7.5;
    fVal = fabs(fVal);

    int integerPart = static_cast<int>(fVal);
    float fractionalPart = fVal - integerPart;
    string binary;

    if (integerPart == 0)
    {
        binary = "0";
    }
    else
    {
        while (integerPart > 0 && integerPart < 8)
        {
            binary = to_string(integerPart % 2) + binary;
            integerPart /= 2;
        }
    }

    if (fractionalPart > 0)
    {
        binary += ".";
        while (fractionalPart > 0)
        {
            fractionalPart *= 2;
            int fractionalBit = static_cast<int>(fractionalPart);
            binary += to_string(fractionalBit);
            fractionalPart -= fractionalBit;

            if (binary.length() > 8)
            {
                break;
            }
        }
    }
    // cout<<binary<<endl;
    string mantissa;
    int exp = 0;

    auto it = find(binary.begin(), binary.end(), '.');

    if (fVal > 1.0)
    {
        exp = it - binary.begin();
        mantissa += binary.substr(0, exp);
        mantissa += binary.substr(exp + 1, 4 - exp);
    }
    else
    {
        int val = it - binary.begin();
        int indx = 0;
        for (int i = val + 1; i < binary.size(); ++i)
        {
            if (binary[i] == '1')
            {
                indx = i;
                break;
            }
            --exp;
            if (exp == -4)
            {
                indx = i + 1;
                break;
            }
        }
        mantissa = binary.substr(indx, 4);
    }

    int biasedexp = exp + 4;
    while (mantissa.size() < 4)
    {
        mantissa += '0';
    }

    return to_string(sign) + bitset<3>(biasedexp).to_string() + mantissa;
}

float ALU::hextofloat(string binary)
{
    int num = hextodecimal(binary);
    bitset<8> bs(num);
    string binnum = bs.to_string();
    int sign = binnum[0] == '1' ? -1 : 1;
    int expo = stoi(binnum.substr(1, 3), nullptr, 2);
    int mantissa = stoi(binnum.substr(4), nullptr, 2);

    float result = sign * pow(2, expo - 4) * (mantissa / 16.0);
    return result;
}

string ALU::add(string hex1, string hex2)
{

    float num1 = hextofloat(hex1);
    float num2 = hextofloat(hex2);

    if (num1 >= 0x80)
        num1 -= 0x100;
    if (num2 >= 0x80)
        num2 -= 0x100;

    int sum = num1 + num2;

    if (sum < 0)
        sum += 256;

    return decimaltohex(sum);
}

string ALU::decimaltohex(int decimalValue)
{
    if (decimalValue < 0)
    {
        decimalValue += 0x100;
    }

    stringstream ss;
    ss << hex << uppercase << setw(2) << setfill('0') << (decimalValue & 0xFF);
    return ss.str();
}
string ALU::binToHexa(string bin)
{
    unsigned long binValue = bitset<8>(bin).to_ulong();
    stringstream ss;
    ss << hex << binValue;
    string hexValue = ss.str();
    for (char &c : hexValue)
    {
        c = toupper(c);
    }
    return hexValue;
}

string ALU::add_float(string h1, string h2)
{
    float x1 = hextofloat(h1);
    float x2 = hextofloat(h2);
    float sum = x1 + x2;
    // cout<<x1<<" "<<x2<<" "<<sum<<endl;
    string binary = floattobin(sum);
    // cout<<binary<<endl;
    string hexa = binToHexa(binary);
    return hexa;
}
string ALU::bitwiseXOR(string hex1, string hex2) {

    bitset<8> bin1(hextodecimal(hex1));
    bitset<8> bin2(hextodecimal(hex2));


    bitset<8> xorResult = bin1 ^ bin2;


    return binToHexa(xorResult.to_string());
}

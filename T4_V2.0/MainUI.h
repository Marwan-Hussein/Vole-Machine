#ifndef MAINUI_H
#define MAINUI_H

#include "Machine.h"
#include "CPU.h"
#include <iostream>
using namespace std;

class MainUI
{
private:
    Machine machine;
    CPU processor;

public:
    MainUI();
    void displayMenu();
    void inputChoice();
    void inputFileName();
    bool isvalid_fileINstructions(string &file);
};

#endif // MAINUI_H
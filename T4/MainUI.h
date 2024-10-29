#ifndef MAINUI_H
#define MAINUI_H

#include "Machine.h"
#include <iostream>
using namespace std;

class MainUI
{
private:
    Machine machine;

public:
    MainUI() = default;
    ~MainUI() = default;
    void displayMenu();
    void inputChoice();
    void inputFileName();
};

#endif // MAINUI_H
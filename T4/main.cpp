#include <iostream>
#include "mainUI.h"
using namespace std;
int main()
{
    MainUI mainUI;
    while (true)
    {
        mainUI.displayMenu();
        mainUI.inputChoice(); // running the program {for input file, load file,output state,runstepbystep} inside this function
    }
    return 0;
}

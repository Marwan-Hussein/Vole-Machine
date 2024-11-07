#include <iostream>
#include "mainUI.h"

using namespace std;
int main()
{
    MainUI mainUI;
    while (true)
    {
        mainUI.displayMenu();
        mainUI.inputChoice();
    }
    return 0;
}

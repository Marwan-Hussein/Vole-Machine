#include <iostream>
#include <string>
#include "Machine.h"
#include "MainUI.h"
using namespace std;

void MainUI::displayMenu()
{
    cout << "\nVole Machine Simulator\n"
            "1. Load program from file\n"
            "2. Display machine state\n"
            "3. Run program step-by-step\n"
            "4. Exit\n"
            "Enter your choice: ";
}

void MainUI::inputChoice()
{
    string choice;
inchoice:
    cin >> choice;

    if (choice == "1")
        inputFileName();
    else if (choice == "2")
        machine.outputState();
    else if (choice == "3")
    {
        string fileName;
        cout << "Enter the program file name: ";
        cin >> fileName;
        machine.loadProgramFile(fileName);
        machine.runStepByStep();
    }
    else if (choice == "4")
    {
        cout << "Exiting the simulator.\n";
        exit(0);
    }
    else
    {
        cout << "invalid choice plz try again: ";
        goto inchoice;
    }
}

void MainUI::inputFileName()
{
    string fileName;
    cout << "Enter the program file name: ";
    cin >> fileName;
    machine.loadProgramFile(fileName);
}

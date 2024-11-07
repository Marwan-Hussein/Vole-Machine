#include <iostream>
#include <string>
#include <fstream>
#include "Machine.h"
#include "MainUI.h"
using namespace std;
// void MainUI::MainUI() {}
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
    {
        while (processor.getProgramCounter() != -2)
        {
            processor.fetchInstruction();
            processor.executeNextInstruction();
            machine.outputState();
            // cout << "Press Enter to continue to the next step: \n";
            cin.ignore();
        }
        // machine.outputState();
    }
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

void MainUI::inputFileName() // input -> load -> isvalid
{
    string fileName;
    cout << "Enter the program file name: ";
    cin >> fileName;
    machine.loadProgramFile(fileName);
    machine.run();
}

bool MainUI::isvalid_fileINstructions(string &file)
{
    ifstream f(file);
    string line;
    while (getline(f, line))
    {
        if (line.length() != 4)
            return 0;
        if (line[0] < '1' || line[0] > 'D')
            return 0;
        for (int i = 1; i < 4; ++i)
            if (line[i] < '0' || line[i] > 'F')
                return 0;
        if (line[0] == '4' && line[1] != '0')
            return 0;
        if (line[0] == 'C' && line.substr(1, 3) != "000")
            return 0;
    }
    return 1;
}
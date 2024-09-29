#include "bits/stdc++.h"
using namespace std;

int main() {
    cout << "choose from following problems to solve:\nproblem 2\nproblem 5\nproblem 8\n";
    string choice;
    input:
    cin >> choice;
    if (choice == "2"){
    cout << 2;

    }
    else if (choice == "5"){
        cout << 5;
    }
    else if(choice == "8"){
        cout << 8;
    }
    else{
        cout << "Invalid input please enter your choice again: ";
        goto input;
    }

    return 0;
}

#include <iostream>           // nodig voor cout (schrijven naar scherm)
#include <iomanip>            // nodig voor setw (veldbreedte definiëren)
#include "tijdsduur.h"
using namespace std;

int getInput() {
    int uurInput = 0;
    int minInput = 0;
    cout << "Voer het aantal uren in: ";
    cin >> uurInput;
    while (cin.fail()) {
        cout << "error, try again";
        cin.clear();
        cin.ignore(265, '\n');
        cin >> uurInput;
    }
    cout << "Voer het aantal minuten in: ";
    cin >> minInput;
    while (cin.fail()) {
        cout << "error, try again";
        cin.clear();
        cin.ignore(265, '\n');
        cin >> minInput;
    }
    cout << endl;
    minInput = minInput + uurInput * 60;
    return minInput;
}

int main() {
    cout << "Dit programma vraagt om 10 tijdsduren in te voeren, en telt deze op..." << endl;
    Tijdsduur tijd(0);
    for (int i = 0; i < 10; i++) {
        int temp = getInput();
        tijd += temp;
    }
    cout << "De tijd is: ";
    tijd.print(cout);
    cout << "Druk op enter..." << endl;
    cin.get();
    return 0;
}

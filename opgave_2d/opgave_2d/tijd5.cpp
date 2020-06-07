#include <iostream>           // nodig voor cout (schrijven naar scherm)
#include <iomanip>            // nodig voor setw (veldbreedte defini�ren)
using namespace std;

// De declaratie van de ADT Tijdsduur:

class Tijdsduur {
public:
    Tijdsduur();
    Tijdsduur(int m);
    Tijdsduur(int h, int m);
    void print(ostream& o) const;
    Tijdsduur& operator+=(const Tijdsduur& right);
    Tijdsduur& operator-=(const Tijdsduur& right);
    Tijdsduur& operator+=(const int& right);
    Tijdsduur& operator-=(const int& right);

private:
    int min;
friend ostream& operator<<(ostream& left, const Tijdsduur& right);
};

const Tijdsduur operator+(const Tijdsduur& left, const Tijdsduur& right);
const Tijdsduur operator-(const Tijdsduur& left, const Tijdsduur& right);

Tijdsduur::Tijdsduur(void) : min(0) {}

Tijdsduur::Tijdsduur(int m) : min(m) {
}

Tijdsduur::Tijdsduur(int h, int m) {
    min = h * 60 + m;
}
// De implementatie van de ADT Tijdsduur:

Tijdsduur& Tijdsduur::operator+=(const Tijdsduur& right) {
    min += right.min;
    return *this;
}

Tijdsduur& Tijdsduur::operator-=(const Tijdsduur& right) {
    min -= right.min;
    return *this;
}

Tijdsduur& Tijdsduur::operator+=(const int& right)
{
    this->min = min + right;
    return *this;
}

Tijdsduur& Tijdsduur::operator-=(const int& right)
{
    this->min = min - right;
    return *this;
}

void Tijdsduur::print(ostream& o) const {
    // Deze functie moet de Tijdsduur wegschrijven naar de uitvoer genaamd "o"
    if (min/60 == 0) {
        o << "          ";
    }
    else if (min/60 > 9) {
        o << min/60 << " uur en ";
    }
    else {
        o << " " << min/60 << " uur en ";
    }

    if (min%60 == 1) {
        o << " " << min%60 << " minuut" << endl;
    }
    else if (min%60 > 9) {
        o << min%60 << " minuten" << endl;
    }
    else {
        o << " " << min%60 << " minuten" << endl;
    }
}

const Tijdsduur operator+(const Tijdsduur& left, const Tijdsduur& right) {
    Tijdsduur copyLeft(left);
    copyLeft += right;
    return copyLeft;
}

const Tijdsduur operator-(const Tijdsduur& left, const Tijdsduur& right) {
    Tijdsduur copyLeft(left);
    copyLeft -= right;
    return copyLeft;
}

ostream& operator<<(ostream& left, const Tijdsduur& right) {
    right.print(left);
    return left;
}

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

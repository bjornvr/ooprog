#include "Tijdsduur.h"

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
    if (min / 60 == 0) {
        o << "          ";
    }
    else if (min / 60 > 9) {
        o << min / 60 << " uur en ";
    }
    else {
        o << " " << min / 60 << " uur en ";
    }

    if (min % 60 == 1) {
        o << " " << min % 60 << " minuut" << endl;
    }
    else if (min % 60 > 9) {
        o << min % 60 << " minuten" << endl;
    }
    else {
        o << " " << min % 60 << " minuten" << endl;
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
#include <iostream>           // nodig voor cout (schrijven naar scherm)
#include <iomanip>            // nodig voor setw (veldbreedte definiëren)
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

private:
    int min;
    int uur;
    void check();
friend ostream& operator<<(ostream& left, const Tijdsduur& right);
};

const Tijdsduur operator+(const Tijdsduur& left, const Tijdsduur& right);
const Tijdsduur operator-(const Tijdsduur& left, const Tijdsduur& right);

Tijdsduur::Tijdsduur(void) : uur(0), min(0) {}

Tijdsduur::Tijdsduur(int m) : uur(0), min(m) {
    check();
}

Tijdsduur::Tijdsduur(int h, int m) : uur(h), min(m) {
    check();
}
// De implementatie van de ADT Tijdsduur:

//...

Tijdsduur& Tijdsduur::operator+=(const Tijdsduur& right) {
    min += right.min;
    uur += right.uur;
    check();
    return *this;
}

Tijdsduur& Tijdsduur::operator-=(const Tijdsduur& right) {
    min -= right.min;
    uur -= right.uur;
    check();
    return *this;
}


void Tijdsduur::check() {
    while (min >= 60) {
        min -= 60;
        uur += 1;
    }
    while (min < 0) {
        uur -= 1;
        min += 60;
    }
}

void Tijdsduur::print(ostream& o) const {
    // Deze functie moet de Tijdsduur wegschrijven naar de uitvoer genaamd "o"
    if (uur == 0) {
        o << "          ";
    }
    else if (uur > 9) {
        o << uur << " uur en ";
    }
    else {
        o << " " << uur << " uur en ";
    }

    if (min == 1) {
        o << " " << min << " minuut";
    }
    else if (min > 9) {
        o << min << " minuten";
    }
    else {
        o << " " << min << " minuten";
    }
 //   o << //oude standaardfunctie

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

// Deze operator hoef je nu nog niet te begrijpen
// In les 7 wordt dit uitgelegd
ostream& operator<<(ostream& left, const Tijdsduur& right) {
    right.print(left);
    return left;
}



int main() {
    Tijdsduur t1(3, 50);        // t1 is 3 uur en 50 minuten
    cout << "t1 = " << t1 << endl;
    const Tijdsduur kw(15);     // kw is 15 minuten
    cout << "kw = " << kw << endl;
    t1 += kw;                   // Tel kw bij t1 op
    cout << "t1 = " << t1 << endl;
    Tijdsduur t2(t1 - kw);      // t2 is t1 min kw
    cout << "t2 = " << t2 << endl;
    cout << "Druk op enter..." << endl;
    cin.get();
    return 0;
}

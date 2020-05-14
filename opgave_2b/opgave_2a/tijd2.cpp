#include <iostream>        // nodig voor cout (schrijven naar scherm)
#include <iomanip>         // nodig voor setw (veldbreedte definiëren)
using namespace std;

// De declaratie van de ADT Tijdsduur:

class Tijdsduur {
public:
//...
    Tijdsduur();
    Tijdsduur(int m);
    Tijdsduur(int h, int m);
    Tijdsduur& eraf(Tijdsduur t);
    void eraf(int t);
    Tijdsduur& erbij(Tijdsduur t);
    void erbij(int t);
    void maal(int multiply);
    void print() const;
//...
private:
    int min;
    int uur;
    void check();
//...
};

Tijdsduur::Tijdsduur(void) : uur(0), min(0) {}

Tijdsduur::Tijdsduur(int m) : uur(0), min(m) {
    check();
}

Tijdsduur::Tijdsduur(int h, int m): uur(h), min(m) {
    check();
}

// De definities van de memberfunctie van de ADT Tijdsduur, oftewel: de implementatie van de ADT Tijdsduur:
Tijdsduur& Tijdsduur::eraf(Tijdsduur t) {
    uur -= t.uur;
    if (t.min < 0)
    {
        t.uur = 0;
        t.min = -t.min;
        erbij(t);
    }
    min -= t.min;
    while (min < 0) {
        min += 60;
        uur -= 1;
    }
    return *this;
}

void Tijdsduur::eraf(int t) {
    if (t < 0)
    {
        t = -t;
        erbij(t);
    }
    min -= t;
    while (min < 0) {
        min += 60;
        uur -= 1;
    }
}

Tijdsduur& Tijdsduur::erbij(Tijdsduur t) {
    uur += t.uur;
    if (t.min < 0)
    {
        t.uur = 0;
        t.min = -t.min;
        eraf(t);
    }
    min += t.min;
    while (min >= 60) {
        min -= 60;
        uur += 1;
    }
    return *this;
}

void Tijdsduur::erbij(int t) {
    if (t < 0)
    {
        t = -t;
        eraf(t);
    }
    min += t;
    while (min >= 60) {
        min -= 60;
        uur += 1;
    }
}

void Tijdsduur::maal(int multiply) {
    min += uur*60;
    uur = 0;
    min = min * multiply;
    check();
}

void Tijdsduur::print() const{
    if (uur == 0) {
        cout << "          ";
    }
    else if(uur > 9){
        cout << uur << " uur en ";
    }
    else {
        cout << " " << uur << " uur en ";
    }

    if (min == 1) {
        cout << " " << min << " minuut";
    }
    else if(min > 9){
        cout << min << " minuten";
    }
    else {
        cout << " " << min << " minuten";
    }
}

void Tijdsduur::check() {
    if (min < 0) {
        eraf(0);
    }
    else if (min > 60) {
        erbij(0);
    }
}
//...

int main() {
    Tijdsduur t1(1, 10);        // t1 is 1 uur en 10 minuten
    const Tijdsduur kw(15);     // kw is 15 minuten
    t1.erbij(kw).erbij(20);     // Tel kw bij t1 op en tel daarna 20 min. erbij op
    cout << "t1 = "; t1.print(); cout << endl;
    cout << "Druk op enter..." << endl;
    cin.get();
    return 0;
}

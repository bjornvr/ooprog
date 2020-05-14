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
    void eraf(Tijdsduur t);
    void erbij(Tijdsduur t);
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
void Tijdsduur::eraf(Tijdsduur t) {
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

    //...	
}

void Tijdsduur::erbij(Tijdsduur t) {
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
    Tijdsduur t1(3, 50);        // t1 is 3 uur en 50 minuten
    cout << "t1 = "; t1.print(); cout << endl;
    const Tijdsduur kw(15);     // kw is 15 minuten
    cout << "kw = "; kw.print(); cout << endl;
    t1.erbij(kw);               // Tel kw bij t1 op
    cout << "t1 = "; t1.print(); cout << endl;
    Tijdsduur t2(t1);           // t2 is een kopie van t1
    t2.eraf(kw);                // Trek kw van t2 af
    cout << "t2 = "; t2.print(); cout << endl;
    t2.maal(7);                 // Vermenigvuldig t2 met 7
    cout << "t2 = "; t2.print(); cout << endl;
    Tijdsduur t3(3, -122);      // t3 is 3 uur minus 122 minuten
    cout << "t3 = "; t3.print(); cout << endl;
    Tijdsduur t4(3, 122);       // t4 is 3 uur plus 122 minuten
    cout << "t4 = "; t4.print(); cout << endl;
    cout << "Druk op de return-toets." << endl;
    cin.get();
    return 0;
}

#include <iostream>
#include <iomanip>
#include "classes.h"

using namespace std;

// definieer hier de benodigde classes... => deze staan in classes.h en classes.c

void printMaandSalaris(const Werknemer& w) {
    cout << "Werknemer: " << w.geefNummer()
        << " verdient: " << setw(8) << setprecision(2) << fixed
        << w.geefSalaris() << " Euro." << endl;
}

int main() {
    Freelancer f(1, 25.75);    // werknemer 1 verdient 25.75 per uur
    VasteKracht v(2, 1873.53); // werknemer 2 verdient 1873.53 per maand
    Stukwerker s(3, 1.05);     // werknemer 3 verdient 1.05 per stuk

    f.werkUren(84);            // werknemer 1 werkt (deze maand) 84 uren
    s.produceerStuks(1687);    // werknemer 3 produceert (deze maand) 1687 stuks

    cout << "Maand 1:" << endl;
    printMaandSalaris(f);
    printMaandSalaris(v);
    printMaandSalaris(s);

    f.werkUren(13.5);          // werknemer 1 werkt (deze maand) 13.5 uren
    s.produceerStuks(0);       // werknemer 3 produceert (deze maand) 0 stuks

    cout << "Maand 2:" << endl;
    printMaandSalaris(f);
    printMaandSalaris(v);
    printMaandSalaris(s);

    cin.get();
    return 0;
}
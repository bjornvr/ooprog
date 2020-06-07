#include <iostream>
#include <iomanip>
#include "classes.h"

using namespace std;

// definieer hier de benodigde classes... => deze staan in de header file classes.c en classes.h

void printMaandSalaris(const Werknemer& w) {
    cout << "Werknemer: " << w.geefNummer()
         << " verdient: " << setw(8) << setprecision(2) << fixed
         << w.geefSalaris() << " Euro." << endl;
}

int main() {
    Freelancer f(1, 25.75);    // werknemer 1 verdient 25.75 per uur
    VasteKracht v(2, 1873.53); // werknemer 2 verdient 1873.53 per maand
    
    f.werkUren(84);            // werknemer 1 werkt (deze maand) 84 uren
    
    cout << "Maand 1:" << endl;
    printMaandSalaris(f);
    printMaandSalaris(v);
    
    f.werkUren(13.5);          // werknemer 1 werkt (deze maand) 13.5 uren
    
    cout << "Maand 2:" << endl;
    printMaandSalaris(f);
    printMaandSalaris(v);
    
    cin.get();
    return 0;
}
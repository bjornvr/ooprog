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
    Stukwerker s(1, 1.05);     // werknemer 1 verdient 1.05 per stuk
    Freelancer f(2, 25.75);    // werknemer 2 verdient 25.75 per uur
    VasteKracht v1(3, 1873.53);// werknemer 3 verdient 1873.53 per maand

    Manager m1(4);             // werknemer 4 is de manager van:
    m1.geeftLeidingAan(s);     // -  werknemer 1
    m1.geeftLeidingAan(f);     // -  werknemer 2
    m1.geeftLeidingAan(v1);    // -  werknemer 3

    VasteKracht v2(5, 2036.18);// werknemer 5 verdient 2036,18 per maand
    Manager m2(6);             // werknemer 6 is de manager van:
    m2.geeftLeidingAan(v2);    // -  werknemer 5
    m2.geeftLeidingAan(m1);    // -  werknemer 4

    s.produceerStuks(678);     // werknemer 1 produceert 678 stuks
    f.werkUren(84);            // werknemer 2 werkt 84 uren

    printMaandSalaris(s);
    printMaandSalaris(f);
    printMaandSalaris(v1);
    printMaandSalaris(m1);
    printMaandSalaris(v2);
    printMaandSalaris(m2);

    cin.get();
    return 0;
}
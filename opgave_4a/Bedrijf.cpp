#include <iostream>
#include <string>
#include <vector>
using namespace std;
#include "Bedrijf.h"
void Bedrijf::neemInDienst(Werknemer& w) {
 werkers.push_back(&w);
}
void Bedrijf::printSalarisOverzicht() const {
 for (auto w: werkers) {
 cout << w->geefNaam() << " : " << w->geefSalaris() << endl;
 }
}

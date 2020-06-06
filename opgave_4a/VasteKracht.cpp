#include <exception>
#include <string>
using namespace std;

#include "VasteKracht.h"
#include "Werknemer.h"

VasteKracht::VasteKracht(string n, double s) : Werknemer(n), maandSalaris(s){
}

double VasteKracht::geefSalaris() const {
	return maandSalaris;
}


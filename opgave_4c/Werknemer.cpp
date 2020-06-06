#include <exception>
#include <string>
using namespace std;

#include "Werknemer.h"
string Werknemer::geefNaam() const {
	return naam;
}


Werknemer::Werknemer(string n): naam(n) {
}

Werknemer::~Werknemer() {
}


#include <exception>
#include <string>
using namespace std;

#include "classes.h"
//Functies klasse Werknemer
int Werknemer::geefNummer() const {
	return nummer;
}


Werknemer::Werknemer(int n): nummer(n) {
}

Werknemer::~Werknemer() {
}

//Functies klasse Werknemer:Freelancer
Freelancer::Freelancer(int n, double ul) : Werknemer(n), uurLoon(ul),gewerkteUren(0) {

}

void Freelancer::werkUren(double u) {
	gewerkteUren = u;
}

double Freelancer::geefSalaris() const {
	double salaris = uurLoon * gewerkteUren;
	return salaris;
}

//Functies klasse Werknemer:Vastekracht
VasteKracht::VasteKracht(int n, double s) : Werknemer(n), maandSalaris(s) {
}

double VasteKracht::geefSalaris() const {
	return maandSalaris;
}
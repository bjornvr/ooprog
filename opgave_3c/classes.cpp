#include <exception>
#include <string>
#include <vector>
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

//Functies klasse Werknemer:Manager
Manager::Manager(int n) : Werknemer(n) {
}

void Manager::geeftLeidingAan(Werknemer& w) {
	loonslaven.push_back(&w);
}

double Manager::geefSalaris() const {
	double salaris = 0.0;
	for (auto w : loonslaven) {
		salaris += w->geefSalaris();
	}
	salaris = (salaris / loonslaven.size()) * 2.0;
	return salaris;
}

//Functies klasse Werknemer:Stukwerker
Stukwerker::Stukwerker(int n, double sl) : Werknemer(n), stukLoon(sl), stuks(0) {
}

void Stukwerker::produceerStuks(int s){
	stuks = s;
}

double Stukwerker::geefSalaris() const {
	double salaris = stukLoon * stuks;
	return salaris;
}

//Functies klasse Werknemer:Vastekracht
VasteKracht::VasteKracht(int n, double s) : Werknemer(n), maandSalaris(s) {
}

double VasteKracht::geefSalaris() const {
	return maandSalaris;
}
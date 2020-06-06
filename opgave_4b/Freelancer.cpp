#include <exception>
#include <string>
using namespace std;

#include "Freelancer.h"
#include "Werknemer.h"

Freelancer::Freelancer(string n, double ul) : Werknemer(n), uurLoon(ul), gewerkteUren(0) {

}

void Freelancer::declareerUren(int u) {
	gewerkteUren = u;
}

double Freelancer::geefSalaris() const {
	double salaris = uurLoon * gewerkteUren;
	return salaris;
}


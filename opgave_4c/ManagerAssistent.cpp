#include <exception>
#include <string>
using namespace std;

#include "ManagerAssistent.h"
#include "Manager.h"
#include "Werknemer.h"

ManagerAssistent::ManagerAssistent(string n, Manager& m) : Werknemer(n) {
	assisteert(m);
}

void ManagerAssistent::assisteert(Manager& m){
	leidinggevende = &m;
}

double ManagerAssistent::geefSalaris() const {
	double salaris = leidinggevende->geefSalaris()*0.45;
	return salaris;
}


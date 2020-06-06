#include <exception>
#include <string>
#include <vector>
using namespace std;

#include "Manager.h"
#include "Werknemer.h"

Manager::Manager(string n) : Werknemer(n) {
}

void Manager::geeftLeidingAan(Werknemer& w) {
	ondergeschikten.push_back(&w);
}

double Manager::geefSalaris() const {
	double salary = 0.0;
	for (auto w : ondergeschikten) {
		salary += w->geefSalaris();
	}
	salary = (salary / ondergeschikten.size())*1.5;
	return salary;
}
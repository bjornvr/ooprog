#include <exception>
#include <string>
#include <vector>
using namespace std;

#ifndef __Manager_h__
#define __Manager_h__

#include "Werknemer.h"

// class Werknemer;
class Manager;

class Manager: public Werknemer
{
	public:

		Manager(string n);
		void geeftLeidingAan(Werknemer& w);
		double geefSalaris() const;
	private:
		std::vector<Werknemer*> ondergeschikten;

};

#endif

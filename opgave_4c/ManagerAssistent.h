#include <exception>
#include <string>
using namespace std;

#ifndef __ManagerAssistent_h__
#define __ManagerAssistent_h__

#include "Manager.h"
#include "Werknemer.h"

class Manager;
// class Werknemer;
class ManagerAssistent;

class ManagerAssistent: public Werknemer
{
	public:

		ManagerAssistent(string n, Manager& m);
		void assisteert(Manager& m);
		double geefSalaris() const;
	private:
		Manager* leidinggevende;

};

#endif

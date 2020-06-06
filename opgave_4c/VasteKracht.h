#include <exception>
#include <string>
using namespace std;

#ifndef __VasteKracht_h__
#define __VasteKracht_h__

#include "Werknemer.h"

// class Werknemer;
class VasteKracht;

class VasteKracht: public Werknemer
{
	public:

		VasteKracht(string n, double s);
		double geefSalaris() const;
	private:
		double maandSalaris;

};

#endif

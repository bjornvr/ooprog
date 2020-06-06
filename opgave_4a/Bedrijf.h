#include <exception>
#include <vector>
using namespace std;

#ifndef __Bedrijf_h__
#define __Bedrijf_h__

#include "Werknemer.h"

class Werknemer;
class Bedrijf;

class Bedrijf
{
	public:

		void neemInDienst(Werknemer& w);
		void printSalarisOverzicht() const;
	private:
		std::vector<Werknemer*> werkers;

};

#endif

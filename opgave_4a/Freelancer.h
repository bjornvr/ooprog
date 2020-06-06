#include <exception>
#include <string>
using namespace std;

#ifndef __Freelancer_h__
#define __Freelancer_h__

#include "Werknemer.h"

// class Werknemer;
class Freelancer;

class Freelancer: public Werknemer
{
	public:

		Freelancer(string n, double ul);
		void declareerUren(int u);
		virtual double geefSalaris() const;
	private:
		double uurLoon;
		int gewerkteUren;

};

#endif

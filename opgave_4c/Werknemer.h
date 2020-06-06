#include <exception>
#include <string>
using namespace std;

#ifndef __Werknemer_h__
#define __Werknemer_h__

class Werknemer;

class Werknemer
{
	public:
		Werknemer(string n);
		string geefNaam() const;
		virtual double geefSalaris() const = 0;

		virtual ~Werknemer();
	private:
		string naam;

};

#endif

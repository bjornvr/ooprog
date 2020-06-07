#include <exception>
#include <string>
using namespace std;

#ifndef __classes_h__
#define __classes_h__

//Defineer klasse Werknemer
class Werknemer;

class Werknemer
{
	public:
		Werknemer(int n);
		int geefNummer() const;
		virtual double geefSalaris() const = 0;

		virtual ~Werknemer();
	private:
		int nummer;

};

//Defineer klasse Werknemer:Freelancer
class Freelancer;

class Freelancer : public Werknemer
{
public:

	Freelancer(int n, double ul);
	void werkUren(double u);
	virtual double geefSalaris() const;
private:
	double uurLoon;
	double gewerkteUren;

};

//Defineer klasse Werknemer:Stukwerker
class Stukwerker;

class Stukwerker : public Werknemer
{
public:

	Stukwerker(int n, double sl);
	void produceerStuks(int s);
	virtual double geefSalaris() const;
private:
	double stukLoon;
	int stuks;

};

//Defineer klasse Werknemer:Vastekracht
class VasteKracht;

class VasteKracht : public Werknemer
{
public:

	VasteKracht(int n, double s);
	double geefSalaris() const;
private:
	double maandSalaris;

};

#endif

#include <iostream> 
using namespace std;
#include "Bedrijf.h" 
#include "VasteKracht.h" 
#include "Freelancer.h" 
#include "Manager.h" 

int main() {
	Bedrijf hhs;
	VasteKracht harry("Harry Broeders", 4023.23);
	hhs.neemInDienst(harry);
	VasteKracht john("John Visser", 4078.34);
	hhs.neemInDienst(john);
	Freelancer beun("Beun de Haas", 60.00);
	hhs.neemInDienst(beun);
	Manager hidde("Hidde de OpleidingsManager");
	hhs.neemInDienst(hidde);
	hidde.geeftLeidingAan(harry);
	hidde.geeftLeidingAan(john);
	Manager sander("Sander de Directeur");
	hhs.neemInDienst(sander);
	sander.geeftLeidingAan(hidde);
	sander.geeftLeidingAan(beun);
	beun.declareerUren(120);
	hhs.printSalarisOverzicht();
	cin.get();
	return 0;
}
#include <iostream>
#include <string>
using namespace std;
int main() {
    cout << "Geef je email adres: ";
    string mailAdres;
    cin >> mailAdres;
    string::size_type indexAapje = mailAdres.find("@");
    if (indexAapje != string::npos) {
        cout << "Gebruiker: "
            << mailAdres.substr(0, indexAapje)
            << endl;
        cout << "Machine: "
            << mailAdres.substr(indexAapje + 1)
            << endl;
    }
    else {
        cout << mailAdres << " is geen geldig email adres!" << endl;
    }
    cout << "Druk op de return-toets." << endl;
    cin.get();
    cin.get();
    return 0;
}
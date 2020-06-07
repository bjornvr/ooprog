// Practicum1b.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
using namespace std;
int main() {
    cout << "Geef een URL op: ";
    string webAdres;
    cin >> webAdres;
    string::size_type indexProto = webAdres.find("://");
    string::size_type indexDir = webAdres.find("/", 8);
    string::size_type indexFile = webAdres.rfind("/");

    if ((indexProto != string::npos) && (indexDir != string::npos)) {
        cout << endl << "Protocol:  " << webAdres.substr(0, indexProto) << endl;
        cout << "Machine:   " << webAdres.substr((indexProto + 3), indexDir - indexProto - 3) << endl;
        if (indexDir == indexFile)
    {
    cout << "Directory:" << endl;
    }
        else {
            cout << "Directory: " << webAdres.substr((indexDir + 1), indexFile - indexDir - 1) << endl;
        }
        cout << "File:      " << webAdres.substr(indexFile + 1) << endl;
    }
    else {
        cout << webAdres << " is geen geldige URL!" << endl;
    }
    cout << endl << "Druk op de enter-toets." << endl;
    cin.get();
    cin.get();
    return 0;
}
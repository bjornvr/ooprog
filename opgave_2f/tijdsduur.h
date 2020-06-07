#pragma once
#ifndef _tijdsduur_
#define _tijdsduur_
#include <iostream>           // nodig voor cout (schrijven naar scherm)
#include <iomanip>            // nodig voor setw (veldbreedte definiëren)
using namespace std;

class Tijdsduur {
public:
    Tijdsduur();
    Tijdsduur(int m);
    Tijdsduur(int h, int m);
    void print(ostream& o) const;
    Tijdsduur& operator+=(const Tijdsduur& right);
    Tijdsduur& operator-=(const Tijdsduur& right);
    Tijdsduur& operator+=(const int& right);
    Tijdsduur& operator-=(const int& right);

private:
    int min;
    friend ostream& operator<<(ostream& left, const Tijdsduur& right);
};

const Tijdsduur operator+(const Tijdsduur& left, const Tijdsduur& right);
const Tijdsduur operator-(const Tijdsduur& left, const Tijdsduur& right);
#endif
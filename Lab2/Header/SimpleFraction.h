#include <iostream>

#ifndef SIMPLEFRACTION_H
#define SIMPLEFRACTION_H

#pragma once

using namespace std;

class SimpleFraction
{
private:
    int numerator;
    int denominator;
    int findGCD(int a, int b);
    SimpleFraction FractionReduction(SimpleFraction simpleFraction);

public:
    SimpleFraction(int numerator, int denominator);
    SimpleFraction();
    SimpleFraction operator+(const SimpleFraction &simpleFraction);
    SimpleFraction operator-(const SimpleFraction &simpleFraction);
    SimpleFraction operator*(const SimpleFraction &simpleFraction);
    SimpleFraction operator/(const SimpleFraction &simpleFraction);
    bool operator==(const SimpleFraction &simpleFraction);

    int GetDenominator();
    int GetNumerator();
    void Print();
};

ostream &operator<<(ostream &s, SimpleFraction &p);
istream &operator>>(istream &s, SimpleFraction &p);

#endif
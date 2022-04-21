#include <iostream>

#ifndef COMPLEX_H
#define COMPLEX_H

#pragma once

using namespace std;

class Complex
{
public:
    Complex();
    Complex(double re);
    Complex(double re, double im);

    Complex operator+(const Complex &c);
    Complex operator-(const Complex &c);
    Complex operator*(const Complex &c);
    Complex operator/(const Complex &c);

    double GetImaginary();
    double GetRe();

    friend ostream &operator<<(ostream &, Complex &);
    friend istream &operator>>(istream &, Complex &);

private:
    double re, im;
};

ostream &operator<<(ostream &s, Complex &c);
istream &operator>>(istream &s, Complex &c);

#endif
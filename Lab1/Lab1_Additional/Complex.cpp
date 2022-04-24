#include "../Header/Complex.h"

Complex::Complex()
{
    this->re = 0;
    this->im = 0;
}
Complex::Complex(double re)
{
    this->re = re;
    this->im = 0;
}
Complex::Complex(double re, double im)
{
    this->re = re;
    this->im = im;
}

Complex Complex::operator+(const Complex &c)
{
    Complex temp;

    temp.re = re + c.re;
    temp.im = im + c.re;

    return temp;
}

Complex Complex::operator-(const Complex &c)
{
    Complex temp;

    temp.re = re - c.re;
    temp.im = im - c.re;

    return temp;
}

Complex Complex::operator*(const Complex &c)
{
    Complex temp;

    temp.re = re * c.re;
    temp.im = re * c.im;

    return temp;
}

Complex Complex::operator/(const Complex &c)
{
    Complex temp;

    double r = c.re * c.re + c.im * c.im;
    temp.re = (re * c.re + im * c.im) / r;
    temp.re = (im * c.re - re * c.im) / r;

    return temp;
}

ostream &operator<<(ostream &s, Complex &c)
{
    s <<"z = "<< c.re << " + i" << c.im << endl;

    return s;
}
istream &operator>>(istream &s, Complex &c)
{
    s >> c.re >> c.im;

    return s;
}

double Complex::GetImaginary()
{
    return im;
}
double Complex::GetRe()
{
    return re;
}

#include "../Header/SimpleFraction.h"

SimpleFraction::SimpleFraction(int numerator, int denominator)
{
    this->numerator = numerator;
    this->denominator = denominator;
}

SimpleFraction::SimpleFraction()
{
    this->numerator = 0;
    this->denominator = 0;
}

SimpleFraction SimpleFraction::operator+(const SimpleFraction &simpleFraction)
{
    int lcm = (this->denominator * simpleFraction.denominator) / findGCD(this->denominator, simpleFraction.denominator);

    int num = (this->numerator * (lcm / this->denominator)) + (simpleFraction.numerator * (lcm / simpleFraction.denominator));

    SimpleFraction newValue(num, lcm);

    return FractionReduction(newValue);
}

SimpleFraction SimpleFraction::operator-(const SimpleFraction &simpleFraction)
{
    int lcm = (this->denominator * simpleFraction.denominator) / findGCD(this->denominator, simpleFraction.denominator);

    int num = (this->numerator * (lcm / this->denominator)) - (simpleFraction.numerator * (lcm / simpleFraction.denominator));

    SimpleFraction newValue(num, lcm);

    return FractionReduction(newValue);
}

SimpleFraction SimpleFraction::operator*(const SimpleFraction &simpleFraction)
{
    SimpleFraction newValue(this->numerator * simpleFraction.numerator, this->denominator * simpleFraction.denominator);

    return FractionReduction(newValue);
}

SimpleFraction SimpleFraction::operator/(const SimpleFraction &simpleFraction)
{
    SimpleFraction newValue(this->numerator * simpleFraction.denominator, this->denominator * simpleFraction.numerator);

    return FractionReduction(newValue);
}

SimpleFraction SimpleFraction::FractionReduction(SimpleFraction simpleFraction)
{
    for (int i = simpleFraction.denominator * simpleFraction.numerator; i > 1; i--)
    {
        if ((simpleFraction.denominator % i == 0) && (simpleFraction.numerator % i == 0))
        {
            simpleFraction.denominator /= i;
            simpleFraction.numerator /= i;
        }
    }

    return simpleFraction;
}

int SimpleFraction::findGCD(int a, int b)
{
    return (a == 0) ? b : findGCD(b % a, a);
}

int SimpleFraction::GetNumerator() { return this->numerator; }

int SimpleFraction::GetDenominator() { return this->denominator; }

//----------------------------------------------------------------------------

ostream &operator<<(ostream &s, SimpleFraction &p)
{
    if (p.GetDenominator() != 1)
    {
        s << "    " << p.GetNumerator() << "\n"
          << "x = - \n"
          << "    " << p.GetDenominator() << "\n";
    }
    else
    {
        s << "x = " << p.GetNumerator();
    }

    return s;
}

istream &operator>>(istream &s, SimpleFraction &p)
{
    int numerator;
    int denominator;

    s >> numerator >> denominator;

    SimpleFraction newValue(numerator, denominator);

    p = newValue;

    return s;
}
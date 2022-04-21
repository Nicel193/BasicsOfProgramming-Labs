#include "../Header/Pair.h"

Pair::Pair(double firstValue, double secondValue)
{
    this->firstValue = firstValue;
    this->secondValue = secondValue;
}

Pair::Pair()
{
    this->firstValue = 0;
    this->secondValue = 0;
}

double Pair::GetFirstValue()
{
    return this->firstValue;
}

double Pair::GetSecondValue()
{
    return this->secondValue;
}
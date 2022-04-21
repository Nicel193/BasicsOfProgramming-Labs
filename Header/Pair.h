#ifndef PAIR_H
#define PAIR_H

#pragma once

class Pair
{
public:
    Pair(double firstValue, double secondValue);
    Pair();

    double GetFirstValue();
    double GetSecondValue();

private:
    double firstValue;
    double secondValue;
};

#endif
#ifndef FUNCTIONRESEARCH_H
#define FUNCTIONRESEARCH_H

#pragma once

#include <iostream>
#include <math.h>
using namespace std;

class FunctionResearch
{
public:
    virtual double Function(double x, int n) = 0;

    static bool GetValidDataFunction(double start, double end, double step, int n);

    static double FindMaxFirstDerivative(double a, double b, double step, int n, FunctionResearch *functionResearch);
};

class FirstFunction : public FunctionResearch
{
public:
    virtual double Function(double x, int n) override;
};

class SecondFunction : public FunctionResearch
{
public:
    virtual double Function(double x, int n) override;
};

#endif
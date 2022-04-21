#include "math.h"

#ifndef QUADRATICEQUATION_H
#define QUADRATICEQUATION_H

#pragma once

enum StateRoots
{
    twoRoots, 
    oneRoot,
    noRoot
};

class QuadraticEquation
{
public:
    QuadraticEquation(double a, double b, double c);

    void FindQuadraticEquation();

    double GetX1();
    double GetX2();
    StateRoots GetStateRoots();

private:
    double a, b, c, x1, x2;
    StateRoots stateRoots;
};

#endif
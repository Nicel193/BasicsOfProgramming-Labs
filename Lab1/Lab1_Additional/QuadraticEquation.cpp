#include "../Header/QuadraticEquation.h"

QuadraticEquation::QuadraticEquation(double a, double b, double c)
{
    this->a = a;
    this->b = b;
    this->c = c;
}

void QuadraticEquation::FindQuadraticEquation()
{
    double D;
    D = this->b * this->b - 4 * this->a * this->c;
    if (D < 0)
    {
        this->stateRoots = noRoot;
    }
    if (D == 0)
    {
        this->x1 = -this->b / (2 * this->a);
        this->stateRoots = oneRoot;
    }
    if (D > 0)
    {
        this->x1 = (-this->b + sqrt(D)) / (2 * this->a);
        this->x2 = (-this->b - sqrt(D)) / (2 * this->a);
        this->stateRoots = twoRoots;
    }
}

double QuadraticEquation::GetX1()
{
    return this->x1;
}
double QuadraticEquation::GetX2()
{
    return this->x2;
}
StateRoots QuadraticEquation::GetStateRoots()
{
    return this->stateRoots;
}
#include <iostream>
#include "../Header/Pair.h"
#include "../Header/Point.h"
#include "../Header/Complex.h"
#include "../Header/Vector.h"
#include "../Header/QuadraticEquation.h"

using namespace std;

void PairTest();
void PointTest();
void ComplexTest();
void VectorTest();
void QuadraticEquationTest();

int main()
{
    PairTest();
    PointTest();
    ComplexTest();
    VectorTest();
    QuadraticEquationTest();

    system("pause");
}

void PairTest()
{
    cout << "Additional Task - (1)" << endl;

    Pair pair(5, 8);

    cout << "First value: " << pair.GetFirstValue() << " Second value: " << pair.GetSecondValue() << endl;
    cout << endl;
}

void PointTest()
{
    cout << "Additional Task - (2)" << endl;

    Point point;

    cin >> point;
    cout << point << endl;
}

void ComplexTest()
{
    cout << "Additional Task - (3)" << endl;

    Complex complex;
    Complex complex1;

    cin >> complex;
    cin >> complex1;

    Complex complexNew = complex + complex1;

    cout << complexNew << endl;
}

void VectorTest()
{
    cout << "Additional Task - (4)" << endl;

    Vector vector(2);
    Vector vector1(2);

    cin >> vector;
    cin >> vector1;

    Vector newVector = vector + vector1;

    cout << newVector << endl;
}

void QuadraticEquationTest()
{
    cout << "Additional Task - (5)" << endl;

    QuadraticEquation a(2, 1, 5);

    a.FindQuadraticEquation();

    if (a.GetStateRoots() == twoRoots)
    {
        cout << "x1 = " << a.GetX1() << "  x2 = " << a.GetX2() << endl;
    }
    if (a.GetStateRoots() == oneRoot)
    {
        cout << "x1 = " << a.GetX1() << endl;
    }
    if (a.GetStateRoots() == noRoot)
    {
        cout << "No roots" << endl;
    }

    cout << endl;
}
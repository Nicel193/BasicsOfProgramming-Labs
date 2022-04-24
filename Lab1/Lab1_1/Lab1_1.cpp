#include <iostream>
#include "../Header/SimpleFraction.h"

using namespace std;

void SimpleFractionAddition();
void SimpleFractionSubtraction();
void SimpleFractionMultiplication();
void SimpleFractionDivision();

int main()
{
    SimpleFraction a;
    cin >> a;
    cout << a << endl;

    SimpleFractionAddition();
    cout << endl;
    SimpleFractionSubtraction();
    cout << endl;
    SimpleFractionMultiplication();
    cout << endl;
    SimpleFractionDivision();
    cout << endl;

    system("pause");

    return 0;
}

void SimpleFractionAddition()
{
    SimpleFraction a(12, 4);
    SimpleFraction b(12, 24);

    SimpleFraction c = a + b;

    cout << c;
}

void SimpleFractionSubtraction()
{
    SimpleFraction a(12, 4);
    SimpleFraction b(12, 24);

    SimpleFraction c = a - b;

    cout << c;
}

void SimpleFractionMultiplication()
{
    SimpleFraction a(12, 4);
    SimpleFraction b(12, 24);

    SimpleFraction c = a * b;

    cout << c;
}

void SimpleFractionDivision()
{
    SimpleFraction a(12, 4);
    SimpleFraction b(12, 24);

    SimpleFraction c = a / b;

    cout << c;
}

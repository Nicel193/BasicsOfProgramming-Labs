#include <iostream>
#include "../Header/CalculationAmount.h"

using namespace std;

int main()
{
    CalculationAmount a(5);
    CalculationAmount b(3);

    cout << CalculationAmount::GetSumData() << endl;

    CalculationAmount c(9);

    cout << CalculationAmount::GetSumData() << endl;

    system("pause");
}
#include <iostream>
#include "../Header/FunctionResearch.h"

using namespace std;

void ResultOutput(double max);
int GetValidInputChoose(int choose);
void GetInputParameters(double &start, double &end, double &step, double &n);

int main()
{
    cout << "Select the function:\n1. Exponentiation\n2. Individual" << endl;

    int choose = GetValidInputChoose(choose);

    double start, end, step, n, max;

    GetInputParameters(start, end, step, n);

    if (choose == 2 && FunctionResearch::GetValidDataFunction(start, end, step, n))
    {
        max = FunctionResearch::FindMaxFirstDerivative(start, end, step, n, new FirstFunction);
    }
    else
    {
        max = FunctionResearch::FindMaxFirstDerivative(start, end, step, n, new SecondFunction);
    }

    ResultOutput(max);

    system("pause");
}

int GetValidInputChoose(int choose)
{
    while (true)
    {
        cin >> choose;

        if (choose != 2 && choose != 1)
            cout << "Select correct answer: ";
        else if (cin.fail())
        {
            cin.clear();
            cout << "Invalid input, try again: ";
        }
        else
        {
            system("cls");
            return choose;
        }
    }
}

void GetInputParameters(double &start, double &end, double &step, double &n)
{
    cout << "Enter start of interval: ";
    cin >> start;
    cout << "Enter end of interval: ";
    cin >> end;
    cout << "Enter step of interval: ";
    cin >> step;
    cout << "Enter n-value (power): ";
    cin >> n;

    system("cls");
}

void ResultOutput(double max)
{
    if (max != INT_MIN)
    {
        cout << "Max = " << max << endl;
    }
    else
    {
        cout << "there is no root of the first derivative" << endl;
    }
}
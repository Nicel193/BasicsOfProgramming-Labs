#include "../Header/FunctionResearch.h"

double FunctionResearch::FindMaxFirstDerivative(double a, double b, double step, int n, FunctionResearch *functionResearch)
{
    double max = INT_MIN;

    double dx = .0000001;

    for (double x = a; x <= b; x += step)
    {
        double y1 = (functionResearch->Function(x + dx, n) - functionResearch->Function(x, n)) / dx;

        if (y1 == 0 && x > max)
            max = x;
    }

    return max;
}

bool FunctionResearch::GetValidDataFunction(double start, double end, double step, int n)
{
    if (start > end || step <= 0 || n < 1)
    {
        if (start > end)
            cout << "Start of interval must be higher than end of interval" << endl;
        if (step <= 0)
            cout << "Step must be higher than 0" << endl;
        if (n < 1)
            cout << "n-value must be higher than 0" << endl;
        system("pause");
        system("cls");
        return false;
    }
    return true;
}

double FirstFunction::Function(double x, int n)
{
    double y = 0;
    
    if (x < 0)
    {
        for (int i = 0; i < n; i++)
        {
            double s = 1;

            for (int j = i; j < n - 1; j++)
                s *= (pow(i, 2) + j);

            y += s;
        }

        y = x - y;
    }
    else
    {
        for (int i = 1; i <= (n - 2); i++)
            y += pow(i - x, 3);
    }

    return y;
}

double SecondFunction::Function(double x, int n)
{
    for (int i = 1; i < n; i++)
        x *= x;

    return x;
}

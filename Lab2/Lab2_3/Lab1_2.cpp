#include <iostream>
#include "Matrix.cpp"
#include "../Header/SimpleFraction.h"

using namespace std;

template <typename T>
void InputMatrix(Matrix<T> &a, int rows, int cols);

bool operator<(SimpleFraction &l, SimpleFraction &r)
{
    int y = l.GetNumerator() * r.GetDenominator() - r.GetNumerator() * l.GetDenominator();

    return (y < 0) ? true : false;
}

int main()
{
    int rows = 2, cols = 2;

    try
    {
        Matrix<int> a(rows, cols);
        Matrix<float> b(rows, cols);
        Matrix<SimpleFraction> c(rows, cols);

        cout << "Integer: ";
        InputMatrix(a, rows, cols);
        cout << "Float: ";
        InputMatrix(b, rows, cols);
        cout << "Simple fraction: ";
        InputMatrix(c, rows, cols);

        cout << "Integer matrix min: ";
        cout << FindMin(a.array, rows, cols) << endl;

        cout << "Float matrix min: ";
        cout << FindMin(b.array, rows, cols) << endl;

        cout << "Simple fraction matrix min: " << endl;
        SimpleFraction min = FindMin(c.array, rows, cols);
        cout << min;
    }
    catch (MatrixException &ex)
    {
        cout << ex.what() << " | IdException: " << ex.GetIdException() << endl;
    }

    system("pause");

    return 0;
}

template <typename T>
void InputMatrix(Matrix<T> &a, int rows, int cols)
{
    cout << "Enter matrix:" << rows << "X" << cols << endl;

    cin >> a;

    cout << endl;
}
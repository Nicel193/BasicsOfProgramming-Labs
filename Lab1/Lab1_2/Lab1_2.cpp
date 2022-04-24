#include <iostream>
#include "../Header/Matrix.h"

using namespace std;

void InputMatrix(Matrix &a, Matrix &b, int rows, int cols);
void MatrixAddition(Matrix a, Matrix b, int rows, int cols);
void MatrixSubtraction(Matrix a, Matrix b, int rows, int cols);
void MatrixMultiplication(Matrix a, Matrix b, int rows, int cols);

void TaskFunction(Matrix &matrix, int rows, int cols);

int main()
{
    int rows = 2, cols = 2;

    try
    {
        Matrix a(rows, cols);
        Matrix b(rows, cols);

        InputMatrix(a, b, rows, cols);
        MatrixAddition(a, b, rows, cols);
        MatrixSubtraction(a, b, rows, cols);
        MatrixMultiplication(a, b, rows, cols);

        TaskFunction(a, rows, cols);
    }
    catch (MatrixException &ex)
    {
        cout << ex.what() << " | IdException: " << ex.GetIdException() << endl;
    }

    system("pause");

    return 0;
}

void InputMatrix(Matrix &a, Matrix &b, int rows, int cols)
{
    cout << "Enter matrix:" << rows << "X" << cols << endl;

    cin >> a;

    cout << endl;
    cout << "Enter matrix 2:" << rows << "X" << cols << endl;

    cin >> b;

    cout << endl;
}

void MatrixAddition(Matrix a, Matrix b, int rows, int cols)
{
    Matrix c = a + b;

    cout << c;
}

void MatrixSubtraction(Matrix a, Matrix b, int rows, int cols)
{
    Matrix c = a - b;

    cout << c;
}

void MatrixMultiplication(Matrix a, Matrix b, int rows, int cols)
{
    Matrix c = a * b;

    cout << c;
}

void TaskFunction(Matrix &matrix, int rows, int cols)
{
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            if (matrix.array[i][j] < 0 && (matrix.array[i][j] % 2))
            {
                matrix.array[i][j] *= 3;
            }
        }
    }

    cout << matrix;
}
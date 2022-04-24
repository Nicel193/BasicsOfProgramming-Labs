#include "../Header/Matrix.h"

Matrix::Matrix(int rows, int cols)
{
    if (rows <= 0 || cols <= 0)
    {
        throw MatrixException("Incorrect matrix size values", 1);
    }

    this->rows = rows;
    this->cols = cols;

    this->array = new int *[rows];

    for (int i = 0; i < rows; i++)
    {
        this->array[i] = new int[cols];
    }
}
Matrix::Matrix(const Matrix &matrix)
{
    this->rows = matrix.rows;
    this->cols = matrix.cols;

    this->array = new int *[this->rows];

    for (int i = 0; i < this->rows; i++)
    {
        this->array[i] = new int[this->cols];
    }

    for (int i = 0; i < this->rows; i++)
    {
        for (int j = 0; j < this->cols; j++)
        {
            this->array[i][j] = matrix.array[i][j];
        }
    }
}
Matrix::~Matrix()
{
    for (int i = 0; i < this->rows; i++)
    {
        delete[] this->array[i];
    }
    delete[] this->array;
}

Matrix Matrix::operator+(const Matrix &matrix)
{
    if (this->cols != matrix.cols || this->rows != matrix.rows)
    {
        throw MatrixException("Matrix addition, cannot be performed", 2);
    }

    Matrix newMatrix(this->rows, this->cols);

    for (int i = 0; i < this->rows; i++)
    {
        for (int j = 0; j < this->cols; j++)
        {
            newMatrix.array[i][j] = this->array[i][j] + matrix.array[i][j];
        }
    }

    return newMatrix;
}
Matrix Matrix::operator-(const Matrix &matrix)
{
    if (this->cols != matrix.cols || this->rows != matrix.rows)
    {
        throw MatrixException("Matrix subtraction, cannot be performed", 3);
    }

    Matrix newMatrix(this->rows, this->cols);

    for (int i = 0; i < this->rows; i++)
    {
        for (int j = 0; j < this->cols; j++)
        {
            newMatrix.array[i][j] = this->array[i][j] - matrix.array[i][j];
        }
    }

    return newMatrix;
}
Matrix Matrix::operator*(const Matrix &matrix)
{
    if(this->cols != matrix.rows) 
    {
        throw MatrixException("Matrix multiplication, cannot be performed", 4);
    }

    Matrix newMatrix(this->rows, matrix.cols);

    for (int i = 0; i < this->rows; i++)
    {
        for (int j = 0; j < matrix.cols; j++)
        {
            newMatrix.array[i][j] = 0;
        }
    }

    for (int i = 0; i < this->rows; i++)
    {
        for (int j = 0; j < matrix.cols; j++)
        {
            for (int k = 0; k < this->cols; k++)
            {
                newMatrix.array[i][j] += this->array[i][k] * matrix.array[k][j];
            }
        }
    }

    return newMatrix;
}

int Matrix::GetRows()
{
    return this->rows;
}
int Matrix::GetCols()
{
    return this->cols;
}

ostream &operator<<(ostream &s, Matrix &m)
{
    for (int i = 0; i < m.GetRows(); i++)
    {
        for (int j = 0; j < m.GetCols(); j++)
        {
            s << m.array[i][j] << " ";
        }
        s << endl;
    }
    s << endl;

    return s;
}
istream &operator>>(istream &s, Matrix &m)
{
    for (int i = 0; i < m.GetRows(); i++)
    {
        for (int j = 0; j < m.GetCols(); j++)
        {
            cin >> m.array[i][j];
        }
    }

    return s;
}

MatrixException::MatrixException(const char *msg, const int idException)
{
    this->idException = idException;
    this->msg = msg;
}

const int MatrixException::GetIdException() { return this->idException; }
const char *MatrixException::what() const throw() { return this->msg; }
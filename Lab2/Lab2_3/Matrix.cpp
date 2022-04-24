#include <iostream>

using namespace std;

class MatrixException : public exception
{
public:
    MatrixException(const char *msg, const int idException)
    {
        this->idException = idException;
        this->msg = msg;
    }

    const int GetIdException() { return this->idException; }
    const char *what() const throw() { return this->msg; }

private:
    int idException;
    const char *msg;
};

template <typename T>
class Matrix
{
public:
    Matrix(int rows, int cols)
    {
        if (rows <= 0 || cols <= 0)
        {
            throw MatrixException("Incorrect matrix size values", 1);
        }

        this->rows = rows;
        this->cols = cols;

        this->array = new T *[rows];

        for (int i = 0; i < rows; i++)
        {
            this->array[i] = new T[cols];
        }
    }
    Matrix(const Matrix &matrix)
    {
        this->rows = matrix.rows;
        this->cols = matrix.cols;

        this->array = new T *[this->rows];

        for (int i = 0; i < this->rows; i++)
        {
            this->array[i] = new T[this->cols];
        }

        for (int i = 0; i < this->rows; i++)
        {
            for (int j = 0; j < this->cols; j++)
            {
                this->array[i][j] = matrix.array[i][j];
            }
        }
    }
    ~Matrix()
    {
        for (int i = 0; i < this->rows; i++)
        {
            delete[] this->array[i];
        }
        delete[] this->array;
    }

    friend ostream &operator<<(ostream &s, Matrix &m)
    {
        for (int i = 0; i < m->rows; i++)
        {
            for (int j = 0; j < m->cols; j++)
            {
                s << m.array[i][j] << " ";
            }
            s << endl;
        }
        s << endl;

        return s;
    }
    friend istream &operator>>(istream &s, Matrix &m)
    {
        for (int i = 0; i < m.rows; i++)
        {
            for (int j = 0; j < m.cols; j++)
            {
                cin >> m.array[i][j];
            }
        }

        return s;
    }

    Matrix operator+(const Matrix &matrix)
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
    Matrix operator-(const Matrix &matrix)
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
    Matrix operator*(const Matrix &matrix)
    {
        if (this->cols != matrix.rows)
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

    T **array;

private:
    int rows, cols;
};

template <typename T>
T FindMin(T **array, int rows, int cols)
{
    T m = array[0][0];

    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            if (array[i][j] < m)
            {
                m = array[i][j];
            }
        }
    }

    return m;
}

template <typename T>
void TaskFunction(Matrix<T> &matrix, int rows, int cols)
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

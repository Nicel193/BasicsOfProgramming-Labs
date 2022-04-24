#include <iostream>

#ifndef MATRIX_H
#define MATRIX_H

#pragma once

using namespace std;

class Matrix
{
public:
    Matrix operator+(const Matrix &matrix);
    Matrix operator-(const Matrix &matrix);
    Matrix operator*(const Matrix &matrix);

    Matrix(int rows, int cols);
    Matrix(const Matrix &matrix);
    ~Matrix();

    int GetRows();
    int GetCols();

    int **array;

private:
    int rows, cols;
};

class MatrixException : public exception
{
public:
    MatrixException(const char *msg, const int idException);
    const char *what() const throw();
    const int GetIdException();

private:
    int idException;
    const char *msg;
};

ostream &operator<<(ostream &s, Matrix &m);
istream &operator>>(istream &s, Matrix &m);

#endif
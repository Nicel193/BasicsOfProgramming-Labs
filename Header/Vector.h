#include <iostream>
using namespace std;

#ifndef VECTOR_H
#define VECTOR_H

#pragma once

class Vector
{
public:
    Vector(int vectorSize);
    Vector(const Vector &vector);
    ~Vector();

    Vector operator+(const Vector &vector);
    Vector operator-(const Vector &vector);
    Vector operator*(const Vector &vector);
    Vector operator/(const Vector &vector);

    int GetVectorSize();

    friend ostream &operator<<(ostream &, Vector &);
    friend istream &operator>>(istream &, Vector &);

private:
    int vectorSize;
    int *vector;
};

ostream &operator<<(ostream &s, Vector &v);
istream &operator>>(istream &s, Vector &v);

#endif
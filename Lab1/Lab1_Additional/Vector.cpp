#include "../Header/Vector.h"

Vector::Vector(int vectorSize)
{
    this->vectorSize = vectorSize;

    this->vector = new int[vectorSize];
}
Vector::Vector(const Vector &matrix)
{
    this->vectorSize = matrix.vectorSize;

    this->vector = new int[vectorSize];

    for (int i = 0; i < this->vectorSize; i++)
    {
        vector[i] = matrix.vector[i];
    }
}
Vector::~Vector()
{
    delete[] this->vector;
}

Vector Vector::operator+(const Vector &vector)
{
    Vector newVector(vector.vectorSize);

    for (int i = 0; i < this->vectorSize; i++)
        newVector.vector[i] = this->vector[i] + vector.vector[i];

    return newVector;
}
Vector Vector::operator-(const Vector &vector)
{
    Vector newVector(vector.vectorSize);

    for (int i = 0; i < this->vectorSize; i++)
        newVector.vector[i] = this->vector[i] - vector.vector[i];

    return newVector;
}
Vector Vector::operator*(const Vector &vector)
{
    Vector newVector(vector.vectorSize);

    for (int i = 0; i < this->vectorSize; i++)
        newVector.vector[i] = this->vector[i] * vector.vector[i];

    return newVector;
}

int Vector::GetVectorSize()
{
    return this->vectorSize;
}

ostream &operator<<(ostream &s, Vector &v)
{
    s << "Coordinate: ";

    for (int i = 0; i < v.vectorSize; i++)
    {
        s << v.vector[i] << " ";
    }
    s << endl;

    return s;
}
istream &operator>>(istream &s, Vector &v)
{
    for (int i = 0; i < v.vectorSize; i++)
    {
        s >> v.vector[i];
    }

    return s;
}

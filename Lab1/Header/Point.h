#include <iostream>

#ifndef POINT_H
#define POINT_H

#pragma once

using namespace std;

class Point
{
public:
    Point(double x, double y, double z);
    Point();

    double GetX();
    double GetY();
    double GetZ();

    friend ostream &operator<<(ostream &, Point &);
    friend istream &operator>>(istream &, Point &);

private:
    double x, y, z;
};

ostream &operator<<(ostream &s, Point &p);
istream &operator>>(istream &s, Point &p);

#endif
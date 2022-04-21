#include "../Header/Point.h"

Point::Point(double x, double y, double z)
{
    this->x = x;
    this->y = y;
    this->z = z;
}

Point::Point()
{
    this->x = 0;
    this->y = 0;
    this->z = 0;
}

double Point::GetX()
{
    return this->x;
}

double Point::GetY()
{
    return this->y;
}

double Point::GetZ()
{
    return this->z;
}

ostream &operator<<(ostream &s, Point &p)
{
    s << "x = " << p.x << " y = " << p.y << " z = " << p.z << endl;

    return s;
}
istream &operator>>(istream &s, Point &p)
{
    s >> p.x >> p.y >> p.z;

    return s;
}
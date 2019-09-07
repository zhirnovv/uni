#include "../headers/util.h"
#include "../headers/vector.h"

#include <iostream>

std::ostream &operator<<(std::ostream &ost, const Vector &v)
{
    ost << '(' << v.getx() << ", " << v.gety() << ')';
    return ost;
}

Vector Vector::operator+(const Vector &v)
{
    return Vector(x + v.x, y + v.y);
}
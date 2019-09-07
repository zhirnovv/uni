#include "../headers/vector.h"

Vector::Vector()
{
    x = y = 0;
}

Vector::Vector(double _x, double _y)
{
    x = _x;
    y = _y;
}

Vector Vector::operator+(const Vector v)
{
    Vector sum;
    
}
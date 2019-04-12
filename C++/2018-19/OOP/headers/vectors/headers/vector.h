#ifndef VECTOR_H
#define VECTOR_H

class Vector
{
  private:
    double x, y;

  public:
    Vector();
    Vector(double _x, double _y);
    ~Vector() {}
    double getx() const { return x; }
    double gety() const { return y; }
    Vector operator+(const Vector v);
};

#endif
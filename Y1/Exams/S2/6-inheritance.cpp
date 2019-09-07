// Inheritance allows us to define a class in term of another class. This means that we can reuse
// data members and member functions from another class within a new class.
//
// Access:
// Base: public, private, protected
// Base->Derived: public, protected
// Base->Outside: public

#include <iostream>

using namespace std;

class Shape {
  public:
    void setWidth(int w) {
      width = w;
    }
    void setHeight(int h) {
      height = h;
    }

  protected: 
    int width;
    int height;
};

class PaintCost {
  public:
    int getCost(int area) {
      return area * 10;
    }
};

class Rectangle: public Shape, public PaintCost {
  public:
    int getArea() {
      return width * height;
    }
};


int main() {
  Rectangle Rect;

  Rect.setWidth(5);
  Rect.setHeight(7);

  cout << "Total area: " << Rect.getArea() << endl;
  cout << "Paint cost: " << Rect.getCost(Rect.getArea()) << endl;

  return 0;
}

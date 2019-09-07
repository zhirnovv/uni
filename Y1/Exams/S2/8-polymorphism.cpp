// ---Polymorphism---
//
// Polymorphism is when a function can possess different definitions and perform different actions.
//
// Polymorphism is divided in two types: static (compile time) or dynamic (runtime).
//
// Static polymorphism is represented in function and operator overloading.
// Dynamic polymorphism is represented via function overriding (virtual functions)

#include <iostream>

using namespace std;

// example of function overloading
class Static {
  public: 
    void get(int value) {
      cout << "value is " << value << endl;
    }

    void get(double value) {
      cout.precision(3);
      cout << "value is " << value << " with two digits after decimal point" << endl; 
    }
};

// example of virtual functions
class Base {
  public: 
    virtual void print() {
      cout << "print from base class" << endl;
    }
};

class Derived : public Base {
  void print() {
    cout << "print from virtal class" << endl;
  }
};

int main() {
  Base *base1;
  Static storage;
  Derived derived;

  base1 = &derived; // redefine functions inside base

  storage.get(1);
  storage.get(3.1415);

  cout << "base1 can ";
  base1 -> print();
  return 0;
}

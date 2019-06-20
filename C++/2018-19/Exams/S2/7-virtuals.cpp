// ---Virtual functions---
// A virtual function is a member function which is declared in the base class and is overridden by
// a derived class. 
//
// Virtual functions ensure that the correct function is called for an object, regardless of the
// type of reference (or pointer) used for the function call.
//
// Virtual functions are used to achieve runtime polymorphism, also called late function binding
//
// The resolving of a function call is done at run-time
//
// RULES:
// 1. Virtual functions cannot be static and cannot be a friend function.
// 2. Virtual functions should be accessed by pointer or reference of base class type to achieve
// runtime polymorphism.
// 3. They are always defined in base class and overridden in derived class.
// 4. The prototype of virtual functions should be the same in base as well as derived class.
// 5. A class may have a virtual destructor but not a virtual constructor.
//

#include <iostream>

using namespace std;

class Base {
  public: 
    virtual void print() {
      cout << "print from base class" << endl;
    }
    void show() {
      cout << "show from base class" << endl;
    }
};

class Derived : public Base {
  void print() {
    cout << "print from derived class" << endl;
  }
  void show() {
    cout << "show from derived class" << endl;
  }
};

int main() {
  Base *basePointer;
  Derived derived;
  basePointer = &derived; // reassign pointer from base class to derived class, this will cause the virtual function to be overridden.

  basePointer->print();
  basePointer->show();
}

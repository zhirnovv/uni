// Virtual functions are member functions that are defined in the base class and overridden in the
// derived class. The function call is resolved at runtime.
//
// Rules:
// 1. Not static
// 2. Accessed via pointer
// 3. Prototype of function should be the same as prototype of derived function
// 4. Defined in base class, overriden in derived class.
// 5. A constructor cannot be virtual.
//
// If there is a pure virtual function defined, then the class is called an abstract class, or an
// interface. Interfaces are used to predefine data members and member functions to be reused in
// different situations.


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

class Interface {
  public: 
    virtual void get() = 0;
};

class DerivedFromInterface : public Interface {
  public:
    void get() {
      cout << "get from derived class" << endl;
    }
};

class Derived : public Base {
  // override base class
  void print() {
    cout << "print from derived class" << endl;
  }

  void show() {
    cout << "show from base class" << endl;
  }
};

int main() {
  Base *basePointer;
  Interface *interface;
  Derived derived;
  DerivedFromInterface derivedFromInterface;

  basePointer = &derived;
  interface = &derivedFromInterface;

  basePointer -> print(); // virtual function, defined at runtime
  basePointer -> show(); // normal function, defined at compile time

  interface -> get(); // interface function, defined at runtime and empty at compile time
}

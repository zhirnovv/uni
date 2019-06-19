// --- C++ Classes ---
// A Class is a user-defined data type which contains data members.
// Data members are the data variables and member functions are the functions used to manipulate these variables.

#include <iostream>
#include <string>

// This is a class
class Car {
  
  public: // available to the entire program
    std::string name;
    
    Car() {
      std::cout << "Default constructor" << std::endl;
      name = "Default car";
    }

    Car(std::string input) {
      std::cout << "Parametrized constructor" << std::endl;
      name = input;
    }

    void printName() {
      std::cout << name;
    }

    int calculateDistance(int time) {
      return speed * time;
    }

  private: // available inside function only
    int speed = 200; 
};

// Class templates act like function templates, useful when a class is used independently of data
// type

template <typename Type> class Array {
  private:
    Type *pointer;
    int size;
  public:
    Array(Type arr[], int s);
    void print();
};

template <typename Type> Array<Type>::Array(Type arr[], int s) {
  pointer = new Type[s];
  size = s;
  
  for(int i = 0; i < size; i++)
      pointer[i] = arr[i];
}

template <typename Type> void Array<Type>::print() {
  for (int i = 0; i < size; i++) {
    std::cout << *(pointer + i);
    std::cout << std::endl;
  }
}

int main() {
  Car generic;
  Car benz("Mercedes Benz");

  std::cout << "benz name is" << benz.name;
  // std::cout << benz.speed; // will not work
  std::cout << "default name is" << generic.name;

  int arr[5];
  for (int i = 0; i < 5; i++)
    arr[i] = i;

  Array<int> classArr(arr, 5);
  classArr.print();
}

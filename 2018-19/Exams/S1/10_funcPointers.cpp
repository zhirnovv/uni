// ---Function pointers---
// A pointer to a function is a pointer to the start of the executable function code.
// Function pointers to not require (de)allocation of memory.

#include <iostream>
using namespace std;

void print(int a)
{
    cout << "Value of the argument is: " << a << endl;
}

int main()
{
    // void (*printPointer)(int) = &print;
    // We can also use the function's name instead of its address
    void (*printPointer)(int) = print;
    printPointer(10);
    return 0;
}
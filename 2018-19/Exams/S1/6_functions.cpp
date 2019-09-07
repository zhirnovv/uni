// ---Functions---

#include <iostream>
using namespace std;

void swapByValue(int a, int b)
{
    int c = b;
    b = a;
    a = c;
}

void swapByPointer(int *a, int *b)
{
    int c = *a;
    *a = *b;
    *b = c;
}

void swapByReference(int &a, int &b)
{
    int c = a;
    a = b;
    b = c;
}

int main()
{
    int a = 2, b = 1;
    cout << a << ' ' << b << endl;
    swapByValue(a, b);
    cout << a << ' ' << b << endl;
    swapByPointer(&a, &b);
    cout << a << ' ' << b << endl;
    swapByReference(a, b);
    cout << a << ' ' << b << endl;
    return 0;
}

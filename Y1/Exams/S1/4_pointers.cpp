// ---Pointers---
#include <iostream>
using namespace std;

int main(int argc, char const *argv[])
{
    // ---Just a pointer lmao---
    // int var1 = 1;
    // cout << "Address:" << endl
    //      << &var1 << endl
    // int *p1 = &var1;
    // cout << "Address in pointer:" << endl
    //      << p1 << endl
    // cout << "Value in pointer: " << endl
    //      << *p1 << endl
    // ---Pointers and arrays---
    // int arr[3] = {10, 100, 200};
    // int *ptr = arr;
    // for (int i = 0; i < 3; i++)
    // {
    //     cout << ptr << endl
    //          << *ptr << endl;
    //     ptr++; // point to the next item
    // }
    // *(arr) = 500;
    // ptr = arr;
    // cout << *ptr;
    // ---Arrays of pointers---
    int arr[3] = {1, 2, 3};
    int *parr[3];
    for (int i = 0; i < 3; i++)
    {
        parr[i] = &arr[i];
    }
    for (int i = 0; i < 3; i++)
    {
        cout << parr[i] << ' ' << *parr[i] << endl;
    }
    return 0;
}

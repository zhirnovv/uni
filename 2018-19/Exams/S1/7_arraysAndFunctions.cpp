// ---Passing an array to a function

// #include <iostream>
// using namespace std;

// void printViaArrayPointer(int *arr, int size)
// {
//     cout << "Length is " << size << endl;
//     for (int i = 0; i < size; i++)
//     {
//         cout << arr[i] << ' ';
//     }
// }

// void printViaArray(int arr[], int size)
// {
//     cout << "Length is " << size << endl;
//     for (int i = 0; i < size; i++)
//     {
//         cout << arr[i] << ' ';
//     }
// }

// int main()
// {
//     int arr[5] = {};
//     for (int i = 0; i < 5; i++)
//     {
//         arr[i] = i;
//         cout << arr[i] << ' ';
//     }
//     cout << endl;
//     printViaArrayPointer(arr, 5);
//     cout << endl;
//     printViaArray(arr, 5);
//     return 0;
// }

// ---Returning an array from a function

// You can not return an array from a function, but you can return a pointer to the array from a function

#include <iostream>
using namespace std;

int *getArray()
{
    // returning the address of a local variable to the outside of the variable's scope is undefined behaviour,
    // which is why we need to use static int
    static int arr[10];
    for (int i = 0; i < 10; i++)
    {
        arr[i] = i;
        cout << arr[i] << ' ';
    }
    cout << endl;
    return arr;
}

int main()
{
    int *pointer;
    pointer = getArray();
    for (int i = 0; i < 10; i++)
    {
        cout << *(pointer + i) << ' ';
    }
    return 0;
}
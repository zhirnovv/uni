// ---Dynamic memory---

// #include <iostream>
// using namespace std;

// int main()
// {
//     double *value = NULL;
//     value = new double; // allocate memory for value
//     *value = 1234.4;
//     cout << *value;
//     delete value; // free up memory taken by value
//     return 0;
// }

// ---Dynamic arrays---

#include <iostream>
using namespace std;

int main()
{
    int *arr;         // declare pointer
    arr = new int[5]; // assign memory for array to pointer
    // Alternative
    int *altarr = new int[5];

    for (int i = 0; i < 5; i++)
    {
        *(arr + i) = i;
        *(altarr + i) = 5 - i;
    }

    cout << "arr: " << endl;
    for (int i = 0; i < 5; i++)
    {
        cout << arr + i << ' ' << *(arr + i) << endl;
    }
    delete[] arr;
    for (int i = 0; i < 5; i++)
    {
        *(arr + i) = i * 2;
    }
    cout << endl
         << "arr check: " << endl;
    for (int i = 0; i < 5; i++)
    {
        cout << arr + i << ' ' << *(arr + i) << endl;
    }

    cout << endl
         << "alt arr: " << endl;
    for (int i = 0; i < 5; i++)
    {
        cout << altarr + i << ' ' << *(altarr + i) << endl;
    }
    delete[] altarr;

    cout << endl
         << "alt arr check: " << endl;
    for (int i = 0; i < 5; i++)
    {
        cout << altarr + i << ' ' << *(altarr + i) << endl;
    }
    return 0;
}

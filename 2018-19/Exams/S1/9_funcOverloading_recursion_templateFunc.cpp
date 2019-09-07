// ---Function overloading---
// Function overloading is defining a function more than once,
// with different arguments and implementations

// #include <iostream>
// using namespace std;

// void print(int a)
// {
//     cout << "Printing int: " << a << endl;
// }
// // overload print with double floating point
// void print(double a)
// {
//     cout << "Printing float: " << a << endl;
// }
// // overload print with char
// void print(char a)
// {
//     cout << "Printing char: " << a << endl;
// }

// int main()
// {
//     float f = 123.4;
//     print(100);
//     print(f);
//     print('e');
//     return 0;
// }

// ---Recursion---
// Recursion is calling a function within the same funciton until some condition is met

// #include <iostream>
// using namespace std;

// int fibonacci(int iterations)
// {
//     switch (iterations)
//     {
//     case 0:
//         return 0;
//     case 1:
//         return 1;
//     default:
//         return fibonacci(iterations - 1) + fibonacci(iterations - 2);
//     }
// }

// int main()
// {
//     cout << fibonacci(30);
//     return 0;
// }

// ---Template functions---
// A template is a formula for creating a generic class or function (i.e. the <vector> class).
// In the case of <vector>, you can use many different data types with <vector> (vector<int>, vector<char>, vector<float>, etc.) and use all <vector> related functions.

#include <iostream>
using namespace std;

template <typename Type>
inline Type const &Max(Type const &a, Type const &b)
{
    return a > b ? a : b;
}

template <typename Type>
inline Type const &Add(Type const &a, Type const &b)
{
    return a + b;
}

int main()
{
    int i1 = 1, i2 = 2;
    double d1 = 1.2, d2 = 1.3;
    char c1 = 'a', c2 = 'b';
    cout << "Int max: " << Max(i1, i2) << endl;
    cout << "Double max: " << Max(d1, d2) << endl;
    cout << "Char max: " << Max(c1, c2) << endl;
    cout << "Int sum: " << Add(i1, i2) << endl;
    cout << "Double sum: " << Add(d1, d2) << endl;
    return 0;
}

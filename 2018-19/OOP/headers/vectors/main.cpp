#include <iostream>
#include "classes/vector.cpp"
#include "classes/util.cpp"

using namespace std;

int main()
{
    Vector v1(1, 1);
    Vector v2(2, 2);
    Vector v3 = v1.add(v2);
    cout << v3;
    return 0;
}

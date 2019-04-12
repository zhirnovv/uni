#include <iostream>
#include <string>

using namespace std;

int main()
{
    auto n;
    cin >> n;
    cout << "Type: " << typeid(n).name() << endl
         << "Value: " << n;
    return 0;
}
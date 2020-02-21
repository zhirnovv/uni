#include <iostream>

using namespace std;

int reverse(int input)
{
    if(input == 0)
        return 0;
    cin >> input;
    reverse(input);
    cout << input << ' ';
}
int main()
{
    int input;
    reverse(input);
}

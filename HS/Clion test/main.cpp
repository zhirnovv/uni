#include <iostream>
using namespace std;

int main(){
    int n = 3, s = 2, d;
    cin >> d;
    while (s <= 947){
        s += d;
        n = n + 2;
    }
    cout << n;
    system("pause");
    return 0;
}
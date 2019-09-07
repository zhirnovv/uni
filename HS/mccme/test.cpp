#include <iostream>
using namespace std;
 int main(){
    int n, k;
    cin >> n;
    k = 100;
    while (n > 100) {
      if (n%100 < k)
        k = n%100;
      n = n/100;
    }
    cout << k << endl;
    return 0;
 }

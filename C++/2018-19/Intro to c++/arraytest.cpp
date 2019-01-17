#include <iostream>
#include "time.h"
#include <cmath>

using namespace std;

int main() {
    srand(time(0));
    int n, sum, min=101, max=0, intervals=0;
    cin >> n;

    int a[n];

    for(int i = 0; i < n; i++) {
        a[i] = rand() % 100;
        sum += a[i];
        cout << a[i] << ' ';
        if(a[i] > max) {
            max = a[i];
        }
        if(a[i] < min) {
            min = a[i];
        }
    }

    cout << endl << sum/n << endl << min << endl << max;

    // int temp;

    // for(int i = 0; i < n; i+=2) {
    //     temp = a[i];
    //     a[i] = a[i+1];
    //     a[i+1] = temp;
    // }

    // for(int i = 0; i < n; i++) {
    //     cout << a[i] << ' ';
    // }
    
    for(int i = 0; i < n; i++){
        if()
    }

    return 0;
}
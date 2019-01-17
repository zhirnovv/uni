#include <iostream>
#include <string>
#include <vector>
#include <cstdio>
using namespace std;

int main() {

    int n;
    cin >> n;
    if (n == 0) {
        return 0;
    }
    char *a = new char[n];
    int *c = new int[33];
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    for (int i = 1; i <= 30; i++) {
        c[i] = 0;
    }
    for (int i = 1; i <= n; i++) {
        c[int(a[i])-64]++;
    }
    for (int i = 1; i <= 30; i++) {
        for (int b = 0; b < c[i] / 2; b++) {
            cout << char(i + 64);
        }
    }
    for (int i = 1; i <= 30; i++) {
        if (c[i]%2 == 1) {
            cout << char(i + 64);
            break;
        }
    }
    for (int i = 30; i >= 1; i--) {
        for (int b = 0; b < c[i] / 2; b++) {
            cout << char(i + 64);
        }
    }

    return 0;
}

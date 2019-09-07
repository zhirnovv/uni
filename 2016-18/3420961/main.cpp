#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void swap(int i, int j){
    int temp;
    i = temp;
    i = j;
    j = temp;
}

int main() {
    vector<int> pair(16);
    vector<int> count(16, 0);

    for (int i = 0; i < 16; ++i) {
        pair[i] = i + 1;
    }

    int n, input;
    cin >> n;

    for (int i = 0; i < n; ++i) {
        cin >> input;
        count[input - 1]++;
    }

    for (int i = 0; i < 16 - 1; ++i) {
        for (int j = 0; j < 16 - i - 1; ++j) {
            if (count[j] < count[j + 1]) {
                swap(count[j], count[j + 1]);
                swap(pair[j], pair[j + 1]);
            }
        }
    }

    for (int k = 0; k < 16; ++k) {
        if (count[k] > 0)
            cout << pair[k] << ' ' << count[k] << endl;
    }

    return 0;
}
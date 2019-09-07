#include <iostream>
#include <vector>
#include <set>

using namespace std;

int main()
{
    int n;
    cin >> n;
    int *a = new int[n];
    multiset <int> a2;
    int k;
    cin >> k;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for (int i = 0; i < k - 1; i++) {
        a2.insert(a[i]);
    }
    for (int i = k - 1; i < n; i++) {
        a2.insert(a[i]);
        cout << *a2.begin() << endl;

        a2.erase(a2.find(a[i - k + 1]));

    }

    if (k > n) {
        cout << *a2.rend() << endl;
    }


    return 0;
}

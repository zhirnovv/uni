#include <iostream>
#include <set>
#include <iterator>
#include <cstdlib>

using namespace std;

int main() {
    int p;
    int n;
    cin >> n;
    multiset <int>a;
    int number;
    for (int i = 0; i < n; i++) {
        cin >> p;
        if (p == 0) {
            cin >> number;
            a.insert(number);

        }
        else if(p==1){

            cout << *a.rbegin()<< endl;

            a.erase(--a.end(), a.end()) ;

        }

    }


    return 0;
}

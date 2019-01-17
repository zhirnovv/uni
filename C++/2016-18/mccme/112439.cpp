#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    int n;
    int maxdividable = -1, max = -1;
    while(cin >> n){
        if(n == 0){
            break;
        }
        if(n > max && n % 7 != 0){
            max = n;
        }
        if(n > maxdividable && n % 7 == 0 && n % 49 != 0){
            maxdividable = n;
        }
    }
    if(maxdividable == -1 || max == -1){
        cout << "1" << endl;
        return 0;
    }
    cout << maxdividable * max;

    return 0;
}

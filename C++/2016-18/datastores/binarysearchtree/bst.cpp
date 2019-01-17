#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    vector <int> v;
    int x, k = 0;
    while(cin >> x && x != 0){
        for(int i = 0; i < v.size(); i++){
            if(x == v[i]){
                k++;
                break;
            }
        }
        if(k == 0){
            v.push_back(x);
        }
        k = 0;
    }
    sort(v.begin(), v.end());
    cout << v[v.size() - 2];
}

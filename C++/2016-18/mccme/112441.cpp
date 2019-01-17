#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main(){
    int n;
    cin >> n;
    if(n == 2){
        int a, b;
        cin >> a >> b;
        cout << a+b;
        return 0;
    }
    long long s1 = 2147483647, m1 = 2147483647, s2 = 2147483647, m2 = 2147483647;
    for(int i = 0; i < n; i++){
        int tmp;
        cin >> tmp;
        if(tmp % 2 == 1){
            if(tmp < s1){
                s2 = s1;
                s1 = tmp;
            }else{
                if(tmp < s2){
                    s2 = tmp;
                }
            }
        }
        if(tmp % 2 == 0){
            if(tmp < m1){
                m2 = m1;
                m1 = tmp;
            }else{
                if(tmp < m2){
                    m2 = tmp;
                }
            }
        }
    }
    cout << min(s1+s2, m1+m2);
    return 0;
}

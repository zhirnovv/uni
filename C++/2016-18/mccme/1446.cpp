#include <iostream>

using namespace std;

int main(){
    int n;
    cin >> n;
    int *a = new int[n];
    int *b = new int[n];
    for (int i = 0; i < n; i++){
        cin >> a[i];
        cin >> b[i];
    }
    for(int j = 0; j < n - 1; j++){
        for(int i = 0; i < n - 1; i++){
            if(b[i] < b[i + 1] || b[i] == b[i + 1] && a[i] > a[i + 1]){
                int temp = a[i];
                a[i] = a[i + 1];
                a[i + 1] = temp;
                temp = b[i];
                b[i] = b[i + 1];
                b[i + 1] = temp;
            }
        }
    }
    for(int i = 0; i < n; i++) cout << a[i] << ' ' << b[i] << endl;
    return 0;
}

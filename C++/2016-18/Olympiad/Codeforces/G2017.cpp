#include <iostream>
using namespace std;
int main() {
    int size, number, lastNumber, music = 1;;
    cin >> size;
    int index = 0;
    for(int i = 0; i < size; i++){
        cin >> number;
        if(lastNumber == size){
            if(number != 1){
                music = i;
                index = i;
                break;


            }
        }
        else
        {
            if(number - lastNumber != 1 && i != 0){
                index = 1;
                music = i;
                break;
            }
        }
        lastNumber = number;
    }
    if(index == 1){
        cout << "YES" << endl << music + 1 << endl;
    }
    else{
        cout << "NO"  << endl;
    }
    return 0;
}

#include <iostream>

using namespace std;

int main(){
    int N, M;
    cin >> N >> M;
    int arr[1000][1000];
    int W;
    cin >> W;
    for (int i = 0; i < N; i++){
        for (int j = 0; j < M; j++){
            arr[i][j] = 0;
        }
    }

    for (int i = 0; i < W; i++){
        int x, y;
        cin >> x >> y;
        x--;
        y--;
        arr[x][y] = 10;
        arr[x-1][y-1]++;
        arr[x-1][y]++;
        arr[x-1][y+1]++;
        arr[x][y-1]++;
        arr[x][y+1]++;
        arr[x+1][y+1]++;
        arr[x+1][y-1]++;
        arr[x+1][y]++;
    }





    for (int i = 0; i < N; i++){
        for (int j = 0; j < M; j++){
            if (arr[i][j] >= 10)
                cout << "* ";
            else cout << arr[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}

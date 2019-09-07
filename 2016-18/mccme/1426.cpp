#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    int n, m, k, i, j;
    cin >> n >> m;
    vector <int> plot;
    vector <int> meskalite;

    for (i = 0; i < n; i++)
        for (j = 0; j < m; j++)
        {
            int x;
            cin >> x;
            plot.push_back(x);
        }

    cin >> k;

    for (i = 0; i < k; i++)
    {
        int x;
        cin >> x;
        meskalite.push_back(x);
    }

    sort(plot.begin(), plot.end());
    sort(meskalite.begin(), meskalite.end());

    k = 0;
    i = plot.size() - 1;
    j = meskalite.size() - 1;
    while ((i+1)*(j+1) > 0){
        if (plot[i] >= meskalite[j])
        {
            k++;
            i--;
            j--;
        }

    else j--;
    }
    cout << k << endl;
    return 0;
}

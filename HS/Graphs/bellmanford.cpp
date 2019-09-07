#include <iostream>
#include <algorithm>
#include <vector>

int n, m, v;
const int INF = 1000000000;
struct edge{
	int a, b, cost;
};

using namespace std;

int main(){
    cin >> n >> m;
    vector <edge> e(m);
    for (int i = 0;i < m; ++i){
        cin >> e[i].a >> e[i].b >> e[i].cost;
        --e[i].a;
        --e[i].b;
    }
    cin >> v;
    --v;

    vector <int> d (n, INF);
	d[v] = 0;
	for (int i = 0; i < n - 1; ++i)
		for (int j =  0 ; j < m; ++j)
			if (d[e[j].a] < INF)
				d[e[j].b] = min (d[e[j].b], d[e[j].a] + e[j].cost);


    for(int i = 0; i < n; i++){
            cout << d[i] << " ";
    }
    return 0;
}

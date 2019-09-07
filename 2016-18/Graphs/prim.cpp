#include <iostream>
#include <vector>
#include <iomanip>
#include <limits.h>
using namespace std;
int main()
{
  int n,m;
  vector < pair<int,int> > g[500];//кроме вершин список смежности хранит и вес ребра
  vector <bool> used(500,0);//вектор использованных вершин
  vector <int> d(500, INT_MAX);//вектор расстояний
  cin >> n >> m;
  int x,y,l;
  pair <int,int> temp;
  for(int i = 0; i < m; i++)
  {
        cin >> x >> y >> l;
        x--;
        y--;
        temp.first=y;
        temp.second=l;
        g[x].push_back(temp);
        temp.first=x;
        g[y].push_back(temp);
    }
    vector < pair<int,int> > path(500);
    d[0] = 0;
    while(true)
    {
        int v =- 1;
        int dist = INT_MAX;
        for(int u = 0; u < n; u++)
                if(!used[u] && dist >= d[u])
                {
                    v = u;
                    dist = d[u];
                }
                if (v == -1)
                  break;
                used[v] = true;
                for(int u = 0; u < g[v].size(); u++)
                    if(!used[g[v][u].first])
                    {
                        if (d[g[v][u].first] > g[v][u].second)
                          path[g[v][u].first] = make_pair(v,g[v][u].first);
                        d[g[v][u].first] = min(d[g[v][u].first],g[v][u].second);
                    }
    }

    long long sum=0;
    for(int i = 0; i < n; i++)
      sum+=d[i];

    cout<<sum<<endl;

    for(int i = 0; i < n-1; i++)
        cout << path[i+1].first+1 << " " << path[i+1].second+1 << endl;

    return 0;
}

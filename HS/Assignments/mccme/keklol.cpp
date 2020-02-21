#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector <int> ans;
vector <bool> used(100);

void dfs(int v, vector <vector <int> > &g)
{
    used[v] = true;
    for (size_t i = 0; i < g[v].size(); i++)
    {
        int to = g[v][i];
        if (used[to] == false) dfs(to, g);
    }
    ans.push_back(v);
}

int mainfunc(int number, int k, vector <vector <int> > &a, vector <bool> &used, int n)
{
    used[number] = true;
    for (int i = 0; i < a[number].size(); i++)
    {
        if (a[number][i] == k)
        {
            return false;
        }

        else if(used[a[number][i]] == false)
        {
            if (mainfunc(a[number][i], k, a,  used, n) == false)
            {
                return false;
            }
        }

    }
    return true;
}


void sort(int n, vector <vector <int> > &g)
{
    for (int i = 1; i <= n; i++)
      used[i] = false;
    ans.clear();
    for (int i = 1; i <= n; i++) if (used[i] == false)
      dfs(i, g);
    reverse(ans.begin(), ans.end());
}

int main()
{
    int n, m;
    cin >> n >> m;
    vector <vector <int> >a(n+1);
    for(int i = 0; i < m; i++)
    {
        int x, y;
        cin >> x >> y;
        a[x].push_back(y);
    }

    for (int i = 1; i < n + 1; i++)
    {
        for (int j = 1; j < n + 1; j++)
        {
            used[j] = false;
        }
        if (mainfunc(i, i, a, used,n) == false)
        {
            cout << "No" << endl;
            return 0;
        }
    }
    cout << "Yes"<< endl;

    for (int j = 1; j < n; j++)
    {
        used[j] = false;
    }

    sort(n,  a);

    for (int i = 0; i < n; i++)
    {
        cout << ans[i] << " ";
    }
    return 0;
}

#include <algorithm>
#include <iostream>
#include <list>
#include <vector>

using namespace std;

const int MAXN = 1000000;

int n;
vector<vector<pair<int, int>>> g(MAXN);
vector<bool> used(MAXN);
vector<int> comp;
vector<int> weights(MAXN);

void dfs(int v) {
  used[v] = true;
  comp.push_back(v);
  for (size_t i = 0; i < g[v].size(); ++i) {
    int to = g[v][i].first;
    if (!used[to])
      dfs(to);
    }
}


void find_comps(int included) {
  used.assign(n, false);

  for (int i = 0; i < n; ++i)
  {
    if (!used[i]) {
      comp.clear();
      dfs(i);

      if (find(comp.begin(), comp.end(), included--) != comp.end()) {
         for (size_t j = 0; j < comp.size(); ++j) {
           cout << comp[j] << " ";
         }
      }
    }
  }
  cout << '0' << endl;
}

int main() {
  int m;
  cin >> n >> m;
  for (int i = 0; i < m; i++) {
    int command;
    cin >> command;
    if (command == 1) {
      int a, b, c;
      cin >> a >> b >> c;
      g[--a].push_back(make_pair(--b, c));
      g[b].push_back(make_pair(a, c));
      weights[a] += c;
      weights[b] += c;
    }
    else {
      int input;
      cin >> input;
      find_comps(input);
    }
  }
  return 0;
}

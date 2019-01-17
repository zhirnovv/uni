#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

vector <vector <int>> g;
vector <bool> used;

bool dfs(int v, int included) {
    used[v] = true;
    if (v == included) return true;

    for (auto& element : g[v]) {
        if (!used[element] && dfs(element, included)) return true;
    }

    return false;
}

int main() {
    int n, m, k;
    cin >> n >> m >> k;
    g.assign(n, {});

    string command;
    int a, b;

    for (int i = 0; i < m; i++) {
        cin >> a >> b;
        g[a - 1].push_back(b - 1);
        g[b - 1].push_back(a - 1);
    }

    for (int i = 0; i < k; i++) {
        cin >> command >> a >> b;
        a -= 1; b -=1;

        if (command == "ask") {
            used.assign(n, false);
            cout << (dfs(a, b) ? "YES" : "NO") << endl;
        } else {
            g[a].erase(remove(g[a].begin(), g[a].end(), b), g[a].end());
            g[b].erase(remove(g[b].begin(), g[b].end(), a), g[b].end());
        }
    }

    return 0;
}

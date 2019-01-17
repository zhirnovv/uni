#include <algorithm>
#include <iostream>
#include <fstream>
#include <vector>
#include <string>

using namespace std;

vector <int> parent;

int find_set(int v) {
    if (v == parent[v])
        return v;
    return parent[v] = find_set(parent[v]);
}

void make_set(int v) {
    parent.push_back(v);
}

void union_sets(pair <int, int> p) {
    int a = find_set(p.first);
    int b = find_set(p.second);

    if (a != b) {
        parent[b] = a;
    }
}

int main() {
    int n, m, k;
    cin >> n >> m >> k;
    vector <pair <string, pair<int, int>>> commands;

    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
    }

    for (int i = 0; i < n; i++) {
        make_set(i);
    }

    for (int i = 0; i < k; i++) {
        string command;
        int a, b;

        cin >> command >> a >> b;
        commands.push_back(make_pair(command, make_pair(a - 1, b - 1)));
    }

    vector <bool> result;

    reverse(commands.begin(), commands.end());
    for (const auto& element : commands) {
        if (element.first == "ask") {
            result.push_back(find_set(element.second.first) == find_set(element.second.second));
        } else {
            union_sets(element.second);
        }
    }

    reverse(result.begin(), result.end());
    for (auto element : result) {
        cout << (element ? "YES" : "NO") << endl;
    }

    return 0;
}

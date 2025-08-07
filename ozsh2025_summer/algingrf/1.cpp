#include <iostream>
#include <vector>
#include <set>
using namespace std;

void dfs(int v, vector<vector<int>>& g, vector<bool>& vis) {
    vis[v] = true;
    for (int u : g[v])
        if (!vis[u])
            dfs(u, g, vis);
}

int main() {
    int n, m;
    cin >> n >> m;

    if (n <= 0) return 0;

    vector<vector<int>> g(n);
    set<int> vs;

    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        if (u < 0 || u >= n || v < 0 || v >= n) return 1;
        g[u].push_back(v);
        g[v].push_back(u);
        vs.insert(u);
        vs.insert(v);
    }

    if (m == 0) {
        cout << (n == 1 ? "yes" : "no") << endl;
        return 0;
    }

    vector<bool> vis(n, false);
    dfs(0, g, vis);

    bool conn = true;
    for (int i = 0; i < n; ++i)
        if (!vis[i]) {
            conn = false;
            break;
        }

    cout << (conn ? "yes" : "no") << endl;
    return 0;
}
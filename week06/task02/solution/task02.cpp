#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1048576;
const int MAXLOG = 21; // 1 << (MAXLOG-1) >= MAXN
int n, root = 1; // Initialisierung von root
vector<int> edges[MAXN];
int tin[MAXN], tout[MAXN], timer = 1;
int up[MAXLOG][MAXN];

void dfs(int v = root, int p = root) {
    tin[v] = timer++;
    up[0][v] = p;
    for (int l = 1; l < MAXLOG; l++)
        up[l][v] = up[l-1][up[l-1][v]];
    for (int w : edges[v]) {
        if (w != p)
            dfs(w, v);
    }
    tout[v] = timer++;
}

bool upper(int a, int b) {
    return tin[a] <= tin[b] && tout[a] >= tout[b];
}

int lca(int a, int b) {
    if (upper(a, b)) return a;
    if (upper(b, a)) return b;
    for (int l = MAXLOG - 1; l >= 0; l--)
        if (!upper(up[l][a], b))
            a = up[l][a];
    return up[0][a];
}

void addEdge(int a, int b) {
    edges[b].push_back(a);
    edges[a].push_back(b);
}

int main() {
    int k, a, b;
    string op;

    cin >> k;

    while(k--) {
        cin >> op >> a >> b;
        if (op == "ADD") {
            addEdge(a, b);
            dfs();
        } else {
            cout << lca(a, b) << endl;
        }
    }

    return 1;
}

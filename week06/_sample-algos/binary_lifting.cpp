#include <bits/stdc++.h>
using namespace std;

const int MAXN, MAXLOG; // 1 << (MAXLOG-1) >= MAXN
int n, root;
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


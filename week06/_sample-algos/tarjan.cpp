#include <bits/stdc++.h>
using namespace std;

const int MAXN = 100001;
vector<int> edges[MAXN], requests[MAXN];
int par[MAXN], anc[MAXN], rnk[MAXN];

int find_set(int v) {
    return (v == par[v]) ? v : (par[v] = find_set(par[v]));
}

void union_sets(int a, int b, int new_anc) {
    a = find_set(a), b = find_set(b);
    if (a != b) {
        if (rnk[a] < rnk[b])
            swap(a, b);
        par[b] = a;
        anc[a] = new_anc;
        if (rnk[a] == rnk[b])
            ++rnk[a];
    }
}

void dfs_tarjan(int v) {
    par[v] = v;
    anc[v] = v;
    for (int w : edges[v])
        if (!par[w]) {
            dfs_tarjan(w);
            union_sets(v, w, v);
        }
    for (int w : requests[v])
        if (par[w])
            printf("%d %d -> %d\n", v, w, anc[find_set(w)]);
}


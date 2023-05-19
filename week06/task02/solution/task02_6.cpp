#include <bits/stdc++.h>
using namespace std;

const int MAXN = 100001;

int root;
vector<int> edges[MAXN];

vector<int> visit2;
int firstVisit[MAXN];
int depth[MAXN];

void lca_dfs(int v = root, int d = 1) {
    firstVisit[v] = visit2.size();
    visit2.push_back(v);
    depth[v] = d;
    for (int w : edges[v]) {
        if (depth[w] != 0) continue;
        lca_dfs(w, d+1);
        visit2.push_back(v);
    }
}

int tree[8*MAXN];
void lca_build_tree(int v = 1, int tl = 0, int tr = visit2.size()-1) {
    if (tl == tr)
        tree[v] = visit2[tl];
    else {
        int tm = (tl + tr) / 2;
        lca_build_tree(2*v, tl, tm);
        lca_build_tree(2*v+1, tm+1, tr);
        if (depth[tree[2*v]] < depth[tree[2*v+1]])
            tree[v] = tree[2*v];
        else
            tree[v] = tree[2*v+1];
    }
}

void lca_prepare() {
    lca_dfs();
    lca_build_tree();
}

int lca_get_tree(int l, int r, int v = 1, int tl = 0, int tr = visit2.size()-1) {
    if (l == tl && r == tr)
        return tree[v];
    int tm = (tl + tr) / 2;
    if (r <= tm)
        return lca_get_tree(l, r, 2*v, tl, tm);
    if (l > tm)
        return lca_get_tree(l, r, 2*v+1, tm+1, tr);
    int lmin = lca_get_tree(l, tm, 2*v, tl, tm);
    int rmin = lca_get_tree(tm+1, r, 2*v+1, tm+1, tr);
    return depth[lmin] < depth[rmin] ? lmin : rmin;
}

int lca(int a, int b) {
    int l = min(firstVisit[a], firstVisit[b]);
    int r = max(firstVisit[a], firstVisit[b]);
    return lca_get_tree(l, r);
}

int main() {
    int q, n = 1;
    cin >> q;
    for (int i = 0; i < q; i++) {
        string op;
        int a, b;
        cin >> op >> a >> b;
        if (op == "ADD") {
            edges[a].push_back(++n);
        } else {
            lca_prepare();
            int lca_ab = lca(a, b);
            cout << lca_ab << endl;
        }
    }
    return 0;
}

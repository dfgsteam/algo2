#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e6+5;
int tree[4*MAXN];

void build(int v, int tl, int tr, int* a) {
    if (tl == tr) {
        tree[v] = a[tl];
    } else {
        int tm = (tl + tr) / 2;
        build(v*2, tl, tm, a);
        build(v*2+1, tm+1, tr, a);
        tree[v] = max(tree[v*2], tree[v*2+1]);
    }
}

void add(int v, int tl, int tr, int pos, int val) {
    if (tl == tr) {
        tree[v] = val;
    } else {
        int tm = (tl + tr) / 2;
        if (pos <= tm)
            add(v*2, tl, tm, pos, val);
        else
            add(v*2+1, tm+1, tr, pos, val);
        tree[v] = max(tree[v*2], tree[v*2+1]);
    }
}

int get(int v, int tl, int tr, int l, int r) {
    if (l > r) 
        return 0;
    if (l == tl && r == tr) {
        return tree[v];
    }
    int tm = (tl + tr) / 2;
    return max(get(v*2, tl, tm, l, min(r, tm)), 
               get(v*2+1, tm+1, tr, max(l, tm+1), r));
}

int main() {
    int k, a, b, n = 1;
    string query;
    cin >> k;
    while (n < k+1) n *= 2;
    int species[n+1];
    memset(species, 0, sizeof(species));
    build(1, 1, n, species);
    while (k--) {
        cin >> query >> a >> b;
        if (query == "ADD") {
            add(1, 1, n, a, b);
        } else {
            cout << get(1, 1, n, a, b) << endl;
        }
    }
    return 0;
}

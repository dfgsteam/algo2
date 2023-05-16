#include <bits/stdc++.h>
using namespace std;

int n, t[4*MAXN];

void build(int a[], int v = 1, int tl = 0, int tr = n) {
    if (tl == tr)
        t[v] = a[tl];
    else {
        int tm = (tl + tr) / 2;
        build(a, 2*v, tl, tm);
        build(a, 2*v + 1, tm + 1, tr);
        t[v] = min(t[2*v], t[2*v + 1]);
    }
}
int get(int l, int r, int v = 1, int tl = 0, int tr = n) {
    if (l > r)
        return INF;
    if (l == tl && r == tr)
        return t[v];
    int tm = (tl + tr) / 2;
    return min(get(l, min(r, tm), 2*v, tl, tm),
	         get(max(l, tm + 1), r, 2*v + 1, tm + 1, tr));
}
void update(int pos, int new_val, int v = 1, int tl = 0, int tr = n) {
    if (tl == tr)
        t[v] = new_val;
    else {
        int tm = (tl + tr) / 2;
        if (pos <= tm)
            update(pos, new_val, 2*v, tl, tm);
        else
            update(pos, new_val, 2*v + 1, tm + 1, tr);
        t[v] = min(t[2*v],    t[2*v + 1]);
    }
}

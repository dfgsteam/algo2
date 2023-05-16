#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e6, MAXLOG = 21, INF = 1e9;
int sparse[MAXLOG][MAXN];
int logsize[MAXN];

void build(int n) {
    int c = 2;
    for (int k = 1; k < MAXLOG; k++) {
        for (int i = 0; i + (1 << (k-1)) < n; i++)
          sparse[k][i] = min(sparse[k-1][i], sparse[k-1][i + (1<<(k-1))]);
        while (c <= min(2 << k, n))
          logsize[c++] = k;
    }
}

int get(int l, int r) {
    if (l > r)
        return INF;
    int lg = logsize[r - l + 1];
    return min(sparse[lg][l], sparse[lg][r - (1<<lg) + 1]);
}


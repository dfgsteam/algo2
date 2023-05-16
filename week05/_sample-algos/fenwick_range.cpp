#include <bits/stdc++.h>
using namespace std;

int n, a[MAXN], t[MAXN];

void init (){
    inc(0, a[0]);
    for (int i = 1; i < n; i++)
        inc(i, a[i] - a[i-1]);
}

int get(int i) {
    int result = 0;
    for (; i >= 0; i = (i & (i+1)) - 1)
        result += t[i];
    return result;
}

void inc(int l, int r, int delta) {
    for (; l < n; l = (l | (l+1)))
        t[l] += delta;
    for (r++; r < n; r = (r | (r+1)))
        t[r] -= delta;
}


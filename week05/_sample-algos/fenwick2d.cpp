#include <bits/stdc++.h>
using namespace std;

int n, m, t[MAXN][MAXN];

int sum(int x, int y) {
    int result = 0;
    for (int i = x; i >= 0; i = (i & (i+1)) - 1)
        for (int j = y; j >= 0; j = (j & (j+1)) - 1)
            result += t[i][j];
    return result;
}

int sum(int x_1, int y_1, int x_2, int y_2) {
    return sum(x_2, y_2) - sum(x_1, y_2) - sum(x_2, y_1) + sum(x_1, y_1);
}

void inc(int x, int y, int delta) {
    for (int i = x; i < n; i = (i | (i+1)))
        for (int j = y; j < m; j = (j | (j+1)))
            t[i][j] += delta;
}


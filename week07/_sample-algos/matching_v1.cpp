#include <bits/stdc++.h>
#define popcnt __builtin_popcount
#define clz __builtin_clz
using namespace std;
const int MAXN = 20;

int dp[1 << MAXN];
int d[MAXN][MAXN];

int dp_matching(int n) {
    dp[0] = 1;
    int maxw = 0;
    for (int mask = 0; mask < (1 << n); mask++) {
        for (int i = mask & -mask, s = mask;
            s; s ^= i, i = s & -s)
            for (int j = mask & -mask, t = mask;
                t; t ^= j, j = t & -t)
                dp[mask] |= dp[mask^i^j] & d[31-clz(i)][31-clz(j)];
        if (dp[mask])
            maxw = max(maxw, popcnt(mask));
    }
    return maxw;
}


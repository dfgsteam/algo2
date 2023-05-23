#include <bits/stdc++.h>
#define popcnt __builtin_popcount
#define ctz __builtin_ctz
using namespace std;
const int MAXN = 20;

int dp[1 << MAXN];
int d[MAXN][MAXN];

int dp_matching(int n) {
    dp[0] = 1;
    int maxw = 0;
    for (int mask = 0; mask < (1 << n); mask++) {
        for (int s = mask, i = ctz(s);
             s; s ^= (1 << i), i = ctz(s))
            for (int t = mask ^ (1 << i), j = ctz(t);
                 t; t ^= (1 << j), j = ctz(t))
            dp[mask] |= dp[mask^(1<<i)^(1<<j)] & d[i][j];
        if (dp[mask])
            maxw = max(maxw, popcnt(mask));
    }
    return maxw;
}


#include <bits/stdc++.h>
using namespace std;
const int MAXN = 12, MAXM = 12;
long long dp[MAXN][1 << MAXM];

void dp_profile(int mask, int i, int nmask, int j, int m) {
    if(j == m) {
        dp[i+1][nmask] += dp[i][mask];
        return;
    }
    if(mask & (1 << j))
        dp_profile(mask, i, nmask, j+1, m);
    else {
        dp_profile(mask, i, nmask | (1 << j), j+1, m);
        if(j+1 < m && !(mask & (1 << (j+1))))
            dp_profile(mask, i, nmask, j+2, m);
    }
}
long long dp_dominocover(int n, int m) {
    dp[0][0] = 1;
    for(int i = 0; i < n; i++)
        for(int mask = 0; mask < (1 << m); mask++)
            dp_profile(mask, i, 0, 0, m);
    return dp[n][0];
}

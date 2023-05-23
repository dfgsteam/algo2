#include <bits/stdc++.h>
#define ctz __builtin_ctz
using namespace std;
const int MAXN = 20;
const int INF = 1 << 30;
int dp[1 << MAXN][MAXN];
int d[MAXN][MAXN];

int dp_tsp(int n) {
    fill(&dp[0][0], &dp[(1<<MAXN)-1][MAXN-1] + 1, INF);
    for (int i = 0; i < n; i++)
        dp[1 << i][i] = 0;
    for (int mask = 0; mask < (1 << n); mask++)
        for (int s = mask, i = ctz(s);
            s; s ^= (1 << i), i = ctz(s))
            for (int t = mask ^ (1 << i), j = ctz(t);
                t; t ^= (1 << j), j = ctz(t))
                dp[mask][i] = min(dp[mask][i],
                dp[mask^(1<<i)][j] + d[j][i]);
		    
    return *min_element(&dp[(1<<n)-1][0], &dp[(1<<n)-1][n]);
}


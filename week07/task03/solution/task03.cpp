#include <bits/stdc++.h>
#define ctz __builtin_ctz
#define MN 100
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

int main () {
	int n, d, m;
	cin >> n >> d >> m;
	
	vector<int> problems[MN];
	
	for (int i = 0; i < n; i++) {
		int c, k;
		cin >> c >> k;
		int mask = 0;
		for (int j = 0; j < k; j++) {
			int tj;
			cin >> tj;
			mask |= 1 << (tj - 1);
		}
		problems[c].push_back(mask);
	}
	dp[0][0] = 1;

	for (int i = 1; i <= d; i++) {
		for (int mask = 0; mask < (1 << m); mask ++) {
			if (!dp[i-1][mask]) continue;
			
			for (unsigned int j = 0; j < problems[i].size(); j++) {
				int problem = problems[i][j];
				if (mask & problem) continue;
				
				int newmask = mask | problem;
				dp[i][newmask] = 1;
			}
		}
	}
	if (dp[d][(1 << m) - 1]) cout << "OK" << endl;
	
	else cout << "Impossible" << endl;
	
	return 0;	
}

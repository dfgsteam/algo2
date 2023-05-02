#include <bits/stdc++.h>
using namespace std;
const int MAXN = 200, MAXM = 40000;
int used[MAXN], match[MAXN], matchto[MAXM];
vector<int> edges[MAXN];

bool dfs_kuhn(int v) {
    used[v] = 1;
    for(auto u: edges[v]) {
        int mtu = matchto[u];
        if(mtu == -1 || !used[mtu] && dfs_kuhn(mtu)) {
            matchto[u] = v;
            match[v] = u;
            return true;
        }
    }
    return false;
}
int kuhn(int n, int m) {
    fill(match, match+n, -1);
    fill(matchto, matchto+m, -1);
    int cnt = 0;
    for(int i = 0; i < n; i++) {
        fill(used, used+n, 0);
        if(dfs_kuhn(i))
            cnt++;
    }
    return cnt;
}
bool dominocover(vector<string> a, int n, int m) {
    int cnt[2] = {0};
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(a[i][j] == '#')
                continue;
            int color = (i+j) & 1;
            cnt[color]++;
            if(color == 1)
                continue;
            int dx[] = {-1, 0, 1, 0};
            int dy[] = {0, -1, 0, 1};
            for(int k = 0; k < 4; k++) {
                int ni = i+dx[k], nj = j+dy[k];
                if(ni < 0 || ni >= n || 
                    nj < 0 || nj >= m || 
                    a[ni][nj] == '#')
                        continue;
                int ij = i*m+j, nij = ni*m+nj;
                edges[ij].push_back(nij);
            }
        }
    }
    return cnt[0] == cnt[1] && kuhn(n*m, n*m) == cnt[0];
}

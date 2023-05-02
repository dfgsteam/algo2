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

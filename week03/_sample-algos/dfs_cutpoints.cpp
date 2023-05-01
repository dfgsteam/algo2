#include <bits/stdc++.h>
using namespace std;
const int MAXN = 100001;
vector<int> edges[MAXN];
int used[MAXN], tin[MAXN], fout[MAXN], timer;
bool cutpoint[MAXN];

void dfs_cutpoint(int v, bool root = true) {
    used[v] = 1;
    fout[v] = tin[v] = ++timer;
    cutpoint[v] = false;
    int fwd_edges = 0;
    for(auto u: edges[v])
        if(!used[u]){
            dfs_cutpoint(u, false);
            fout[v] = min(fout[v], fout[u]);
            if(tin[v] <= fout[u] && !root)
                cutpoint[v] = true;
            fwd_edges++;
        }
        else
            fout[v] = min(fout[v], tin[u]);
    if(root && fwd_edges >= 2)
        cutpoint[v] = true;
}

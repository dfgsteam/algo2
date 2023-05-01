#include <bits/stdc++.h>
using namespace std;
const int MAXN = 100001;
vector<int> edges[MAXN], topsort;
int used[MAXN];

void dfs_topsort(int v){
    used[v] = 1;
    for(auto u: edges[v])
        if(!used[u])
            dfs_topsort(u);
    topsort.push_back(v);
}
void find_topsort(int n) {
    for(int i = 1; i <= n; i++)
        if(!used[i])
            dfs_topsort(i);
    reverse(topsort.begin(), topsort.end());
}

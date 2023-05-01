#include <bits/stdc++.h>
using namespace std;
const int MAXN = 100001;
vector<int> edges[MAXN];
int used[MAXN], tin[MAXN], tout[MAXN], timer = 1;

void dfs(int v){
    used[v] = 1;
    tin[v] = timer++;
    for(auto u: edges[v])
        if(!used[u])
            dfs(u);
    tout[v] = timer++;
}
bool ancestor(int u, int v) {
    return tin[u] < tin[v] && tout[u] > tout[v];
}

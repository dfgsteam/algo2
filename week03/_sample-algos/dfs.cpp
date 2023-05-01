#include <bits/stdc++.h>
using namespace std;
const int MAXN = 100001;
vector<int> edges[MAXN];
int used[MAXN];

void dfs(int v) {
    used[v] = 1;
    for(auto u: edges[v]) 
    	if(!used[u])
            dfs(u);
}

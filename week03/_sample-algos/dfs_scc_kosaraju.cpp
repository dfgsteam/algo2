#include <bits/stdc++.h>
using namespace std;
const int MAXN = 100001;
vector<int> edges[MAXN], redges[MAXN], color_rep, topsort;
int color[MAXN], used[MAXN];

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
void dfs_reverse(int v, int comp = 1) {
    color[v] = comp;
    for(auto u: redges[v])
        if(!color[u]) 
            dfs_reverse(u, comp);
}
int find_scc(int n) {
    find_topsort(n);
    int colorcnt = 0;
    for(int i = 0; i < n; i++)
        if(!color[topsort[i]]) {
            color_rep.push_back(topsort[i]);
            dfs_reverse(topsort[i], ++colorcnt);
        }
    return colorcnt;
}

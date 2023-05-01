#include <bits/stdc++.h>
using namespace std;
const int MAXN = 100001, MAXM = 200001;
struct edge {
    int o, ind;
};
vector<edge> edges[MAXN];
int tin[MAXN], fout[MAXN], timer;
int bridge[MAXM];

void dfs_bridge(int v, int p = -1, int pind = -1) {
    fout[v] = tin[v] = timer++;
    for(auto e: edges[v]) {
        if(e.o == p && e.ind == pind)
            continue;
        if(!tin[e.o]) {
            dfs_bridge(e.o, v, e.ind);
            fout[v] = min(fout[v], fout[e.o]);
            if(tin[v] < fout[e.o])
                bridge[e.ind] = 1;
        }
        else
            fout[v] = min(fout[v], tin[e.o]);
    }
}


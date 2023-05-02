#include <bits/stdc++.h>
using namespace std;
const int MAXN = 202, INF = 1000000000;
struct edge {
    int v, u, c, flow;
};
int dis[MAXN], ptr[MAXN];
vector<edge> edglist;
vector<int> edgind[MAXN];

void dinic_addedge(int u, int v, int c) {
    edgind[u].push_back((int) edglist.size());
    edglist.push_back({u, v, c, 0});
    edgind[v].push_back((int) edglist.size());
    edglist.push_back({v, u, 0, 0});
}
bool bfs_dinic(int s, int t) {
    queue<int> q;
    q.push(s);
    dis[s] = 0;
    while(!q.empty() && dis[t] == -1) {
        int v = q.front();
        q.pop();
        for(auto ind: edgind[v]) {
            auto e = edglist[ind];
            if(dis[e.u] == -1 && e.flow < e.c) {
                q.push(e.u);
                dis[e.u] = dis[v]+1;
            }
        }
    }
    return dis[t] != -1;
}
int dfs_dinic(int v, int t, int flow) {
    if(!flow)
        return 0;
    if(v == t)
        return flow;
    for(; ptr[v] < (int) edgind[v].size(); ptr[v]++) {
        int ind = edgind[v][ptr[v]];
        auto e = edglist[ind];
        if(dis[e.u] != dis[v]+1)
            continue;
        int pushed = dfs_dinic(e.u, t, min(flow, e.c-e.flow));
        if(pushed) {
            edglist[ind].flow += pushed;
            edglist[ind ^ 1].flow -= pushed;
            return pushed;
        }
    }
    return 0;
}
long long dinic(int n, int s, int t) {
    long long flow = 0;
    while(true) {
        fill(dis, dis+n, -1);
        if(!bfs_dinic(s, t))
            break;
        fill(ptr, ptr+n, 0);
        while(int pushed = dfs_dinic(s, t, INF)) 
            flow += pushed;
    }
    return flow;
}
bool gridpath(vector<string> a, int n, int m) {
    int s = 0, t = 2*n*m+1;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(a[i][j] == '#')
            	continue;
            int vin = i*m+j+1, vout = vin+n*m;
            int capv = (a[i][j] == 'B') ? 2 : 1;
            dinic_addedge(vin, vout, capv);
            if(a[i][j] == 'A' || a[i][j] == 'C')
                dinic_addedge(s, vin, 1);
            else if(a[i][j] == 'B')
                dinic_addedge(vout, t, 2);
            int dx[] = {-1, 0, 1, 0};
            int dy[] = {0, -1, 0, 1};
            for(int k = 0; k < 4; k++) {
                int ni = i+dx[k], nj = j+dy[k];
                if (ni < 0 || ni >= n || 
                    nj < 0 || nj >= m || 
                    a[ni][nj] == '#')
                        continue;
                int uin = ni*m+nj+1;
                dinic_addedge(vout, uin, 1);
            }
        }
    }
    return dinic(t+1, s, t) == 2;
}

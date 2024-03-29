#include <bits/stdc++.h>
using namespace std;
const int MAXN = 202, INF = 1e9;
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
    if(!flow || v == t)
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
        fill(dis, dis+n+1, -1);
        if(!bfs_dinic(s, t))
            break;
        fill(ptr, ptr+n+1, 0);
        while(int pushed = dfs_dinic(s, t, INF)) 
            flow += pushed;
    }
    return flow;
}

int main(){
    int N, M;
    long long a, b, c, sum;
    cin >> N >> M;
    for(int i = 0; i < M; i++){
        cin >> a >> b >> c;
        dinic_addedge(a, b, c);
        dinic_addedge(b, a, c);
    }
    cout << dinic(N, 1, N) << endl;
}

#include <bits/stdc++.h>
//#define INF (1LL << 62)
using namespace std;


const int MAXN = 10000;
const int INF = 1 << 30;

struct edge {
    int u, cost;
};

vector<edge> edges[MAXN];

int used[MAXN+1], d[MAXN+1];

void dijkstra (int s, int n) {
    fill(d, d+n+1, INF);
    d[s] = 0;
    set<pair<int, int>> dst;
    dst.insert({d[s], s});
    while (!dst.empty()) {
        int v = dst.begin()->second;
        dst.erase(dst.begin());
        for (auto e : edges[v])
            if (d[v] + e.cost < d[e.u]) {
                dst.erase({d[e.u], e.u});
                d[e.u] = d[v] + e.cost;
                dst.insert({d[e.u], e.u});
            }
    }
}


int main() {
    int vertices_num, edges_num, pos_1, pos_2;
    cin >> vertices_num >> edges_num;
    while(edges_num--) {
        cin >> pos_1 >> pos_2;
        edges[pos_1].push_back({pos_2, 1});
        edges[pos_2].push_back({pos_1, 1});
    }
    long double sum = 0;
 //   for (int edges_read = 0; edges_read<edges_num; edges_read++) {
    for(int j=0; j< MAXN; j++){
        dijkstra(j, MAXN);
        for(int i=0; i< MAXN; i++)
            if (d[i] != INF)
                sum +=d[i];
    }
    double res = 1 / (sum / (vertices_num * (vertices_num-1)));
    // cerr << (sum / (vertices_num * (vertices_num-1))) << endl;
    cout << res << endl;
    return 0;
}
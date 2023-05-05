#include <bits/stdc++.h>
//#define INF (1LL << 62)
using namespace std;


const int MAXN = 5000;
typedef pair<int,int> edge ;
vector <edge> edges[MAXN];
int tin[MAXN], fout[MAXN], t;
vector <int> bridges;

void dfs_bridge(int v, edge prev = { -1 , -1}) {
    fout [v] = tin[v] = ++t;
    for (auto e: edges [v]) {
        if (e == prev)
            continue;
    if (!tin[e.first]) {
        dfs_bridge (e.first, {v , e.second });
        fout [v] = min (fout[v], fout[e.first]);
        if ( tin [ v ] < fout [ e . first ])
            bridges.push_back(e.second);
    } else
        fout [v] = min(fout[v], tin[e.first]);
    }
}

int main() {
    int n, m, a, b;
    cin >> n >> m;
    while(m--) {
        cin >> a >> b;

    }

    return 0;
}
#include <bits/stdc++.h>
#define ll long long
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

int main() {
    int M, Q, a, b, bcounter=0;
    char c;
    bool check=false;
    cin >> M;
    for (ll i=0; i<M; i++) {
        cin >> a >> b;
        edge tmp1 = {b, bcounter};
        edge tmp2 = {a, bcounter};
        bcounter++;
        edges[a].push_back(tmp1);
        edges[b].push_back(tmp2);
    }
    cin >> Q;
    for (ll i=0; i<Q; i++) {
        fill(bridge, bridge+MAXM, 0);
        fill(tin, tin+MAXN, 0);
        fill(fout, fout+MAXN, 0);
        timer=0;
        dfs_bridge(1);
        check=false;
        cin >> c >> a >> b;
        switch (c) {
            case 'R':
                for (ll j=0; j<edges[a].size(); j++) {
                    //cout << edges[a][j].o << " " << edges[a][j].ind << " " << bridge[edges[a][j].ind] << endl;
                    if (edges[a][j].o==b&&bridge[edges[a][j].ind]==0) {
                        ll tmpind = edges[a][j].ind;
                        edges[a].erase(edges[a].begin()+j);
                        for (ll v=0; v<edges[b].size(); v++) {
                            if (edges[b][v].ind==tmpind) {
                                edges[b].erase(edges[b].begin()+v);
                                break;
                            }
                        }
                        check=true;
                        cout << "Va bene!" << endl;
                        break;
                    }
                }
                if (!check) {
                    cout << "Impossibile!" << endl;
                }
                break;
            case 'C':
                edge tmp1 = {b, bcounter};
                edge tmp2 = {a, bcounter};
                bcounter++;
                edges[a].push_back(tmp1);
                edges[b].push_back(tmp2);
                break;
        }
    }
}
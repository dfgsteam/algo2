#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1048576;
const int MAXLOG = 21; // 1 << (MAXLOG-1) >= MAXN
int n, root = 1; // Initialisierung von root
vector<int> edges[MAXN];
int tin[MAXN], tout[MAXN], timer = 1;
int up[MAXLOG][MAXN];

void dfs(int v = root, int p = root) {
    tin[v] = timer++;
    up[0][v] = p;
    for (int l = 1; l < MAXLOG; l++)
        up[l][v] = up[l-1][up[l-1][v]];
    for (int w : edges[v]) {
        if (w != p)
            dfs(w, v);
    }
    tout[v] = timer++;
}
bool upper(int a, int b) {
    return tin[a] <= tin[b] && tout[a] >= tout[b];
}

int lca(int a, int b) {
    if (upper(a, b)) return a;
    if (upper(b, a)) return b;
    for (int l = MAXLOG - 1; l >= 0; l--)
        if (!upper(up[l][a], b))
            a = up[l][a];
    return up[0][a];
}

void addEdge(int a, int b) {
    edges[b].push_back(a);
    edges[a].push_back(b);
}

int main() {
    int k, temp, temp2;
    vector<int> inp, points;

    cin >> k;
    for (int i=2; i<=k; i++) {
        cin >> temp;
        addEdge(i, temp);
    }
    dfs();
    while(true) {
        cin >> temp;
        if (temp == 0) {
            return 0;
        } else {
            inp.clear();
            points.clear();
            while(temp--) {
                cin >> temp2;
                inp.push_back(temp2);
            }
            
            while (inp.size() != 1) {
                for (int item = 0; item < inp.size()-1; item++)
                    points.push_back(lca(inp[item], inp[item+1]));
                inp = points;
                points.clear();
            }
            cout << inp[0]++ << endl;
        }
    }
    return 0;
}

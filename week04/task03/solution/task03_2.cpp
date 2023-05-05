#include <bits/stdc++.h>
using namespace std;

const int MAXN = 4600;

vector<int> edges[MAXN];
int used[MAXN], tin[MAXN], fout[MAXN], t;
bool cutpoint[MAXN];

void dfs_cutpoint(int v, bool root = true) {
    used[v] = 1;
    fout[v] = tin[v] = ++t;
    cutpoint[v] = false;
    int edgecnt = 0;
    for (auto u : edges[v]) {
        if (!used[u]) {
            dfs_cutpoint(u, false);
            fout[v] = min(fout[v], fout[u]);
            if (tin[v] <= fout[u] && !root)
                cutpoint[v] = true;
            edgecnt++;
        } else {
            fout[v] = min(fout[v], tin[u]);
        }
    }
    if (root && edgecnt >= 2)
        cutpoint[v] = true;
}

int main() {
    srand(time(NULL));
    int n, m;
    cin >> n >> m;
    while (m--) {
        int u, v = 0;
        cin >> u >> v;
        cout << u << v;
        edges[u--].push_back(v--);
        edges[v--].push_back(u--);
    }
    cout << "ok";
    dfs_cutpoint();
    cout << "Minimum cut: " << min_cut << endl;
    return 0;
}
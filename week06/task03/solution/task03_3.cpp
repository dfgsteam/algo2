#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1048576;
const int MAXLOG = 21; // 1 << (MAXLOG-1) >= MAXN
int n, root = 1; // Initialisierung von root
int edges[MAXN][2], edge_count = 0;
int tin[MAXN], tout[MAXN], timer = 1;
int up[MAXLOG][MAXN];
int lca_memo[MAXN][MAXLOG];

void dfs(int v = root, int p = root) {
    tin[v] = timer++;
    up[0][v] = p;
    for (int l = 1; l < MAXLOG; l++)
        up[l][v] = up[l-1][up[l-1][v]];
    for (int i = 0; i < edge_count; i++) {
        int a = edges[i][0], b = edges[i][1];
        if (b == v && a != p)
            dfs(a, v);
        else if (a == v && b != p)
            dfs(b, v);
    }
    tout[v] = timer++;
}

bool upper(int a, int b) {
    return tin[a] <= tin[b] && tout[a] >= tout[b];
}

int lca(int a, int b) {
    if (upper(a, b)) return a;
    if (upper(b, a)) return b;
    if (lca_memo[a][0] != -1 && lca_memo[b][0] != -1)
        return lca_memo[a][0];
    for (int l = MAXLOG - 1; l >= 0; l--)
        if (!upper(up[l][a], b))
            a = up[l][a];
    if (lca_memo[a][0] == -1) {
        lca_memo[a][0] = a;
        for (int l = 1; l < MAXLOG; l++)
            lca_memo[a][l] = lca(lca_memo[a][l-1], lca_memo[up[l-1][a]][l-1]);
    }
    if (lca_memo[b][0] == -1) {
        lca_memo[b][0] = b;
        for (int l = 1; l < MAXLOG; l++)
            lca_memo[b][l] = lca(lca_memo[b][l-1], lca_memo[up[l-1][b]][l-1]);
    }
    return lca_memo[a][0];
}

void addEdge(int a, int b) {
    edges[edge_count][0] = a;
    edges[edge_count][1] = b;
    edge_count++;
}

int main() {
    memset(lca_memo, -1, sizeof(lca_memo));
    int k, temp, temp2;

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
            int inp[MAXN], points[MAXN], inp_count = 0, points_count = 0;
            while(temp--) {
                cin >> temp2;
                inp[inp_count++] = temp2;
            }
            while (inp_count != 1) {
                for (int item = 0; item < inp_count-1; item++)
                    points[points_count++] = lca(inp[item], inp[item+1]);
                memcpy(inp, points, sizeof(int) * points_count);
                inp_count = points_count;
                points_count = 0;
            }
            cout << inp[0]++ << endl;
        }
    }
    return 0;
}

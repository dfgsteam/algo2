#include <iostream>
#include <vector>
#include <string>
using namespace std;

const int MAXN = 1048576;
const int MAXLOG = 21; // 1 << (MAXLOG-1) >= MAXN
int n, root = 1; // Initialisierung von root
int edges[MAXN][2];
int tin[MAXN], tout[MAXN], timer = 1;
int up[MAXLOG][MAXN];

void dfs() {
    tin[root] = timer++;
    up[0][root] = root;
    for (int l = 1; l < MAXLOG; l++)
        up[l][root] = up[l-1][up[l-1][root]];
    int stack[MAXN], top = 0;
    stack[top++] = root;
    while (top > 0) {
        int v = stack[--top];
        for (int i = 0; i < n-1; i++) {
            int w = edges[i][0] == v ? edges[i][1] : edges[i][0];
            if (w != up[0][v]) {
                tin[w] = timer++;
                up[0][w] = v;
                for (int l = 1; l < MAXLOG; l++)
                    up[l][w] = up[l-1][up[l-1][w]];
                stack[top++] = w;
            }
        }
        tout[v] = timer++;
    }
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
    edges[n-1][0] = a;
    edges[n-1][1] = b;
    n++;
}

int main() {
    int k, a, b;
    string op;

    cin >> k;

    while(k--) {
        cin >> op >> a >> b;
        if (op == "ADD") {
            addEdge(a, b);
        } else {
            dfs();
            cout << lca(a, b) << endl;
        }
    }

    return 0;
}

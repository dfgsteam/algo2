#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1048576;
vector<int> edges[MAXN];  // Adjazenzliste des Baums
int parent[MAXN];  // Elternknoten im Baum
int ancestor[MAXN];  // Vorfahre des Knotens im Baum
bool visited[MAXN];  // Besuchsmarkierung des Knotens

void makeSet(int n) {
    for (int i = 1; i <= n; i++) {
        parent[i] = i;
        ancestor[i] = i;
        visited[i] = false;
    }
}

int findSet(int x) {
    if (x != parent[x]) {
        parent[x] = findSet(parent[x]);
    }
    return parent[x];
}

void unionSets(int x, int y) {
    parent[y] = x;
    ancestor[x] = x;
}

void dfs(int v) {
    visited[v] = true;
    for (int u : edges[v]) {
        if (!visited[u]) {
            dfs(u);
            unionSets(v, u);
            ancestor[findSet(v)] = v;
        }
    }
}

int lca(int a, int b) {
    int root = findSet(1);
    makeSet(root);
    dfs(root);
    while (a != ancestor[a]) {
        int new_a = ancestor[a];
        ancestor[a] = root;
        a = new_a;
    }
    while (b != ancestor[b]) {
        int new_b = ancestor[b];
        ancestor[b] = root;
        b = new_b;
    }
    return a;
}

void addEdge(int a, int b) {
    edges[a].push_back(b);
    edges[b].push_back(a);
}

int main() {
    int k, a, b;
    bool sorted = true;
    string op;

    cin >> k;

    while(k--) {
        cin >> op >> a >> b;
        if (op == "ADD") {
            addEdge(a, b);
        } else {
            cout << lca(a, b) << endl;
        }
    }
    return 0;
}
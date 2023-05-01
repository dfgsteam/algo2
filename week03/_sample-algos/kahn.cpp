#include <bits/stdc++.h>
using namespace std;
const int MAXN =  100001;

int indeg[MAXN];
vector<int> edges[MAXN];

vector<int> kahn(int n) {
    vector<int> res;
    queue<int> q;
    for (int i = 1; i <= n; i++)
        if (!indeg[i])
            q.push(i);
    while (!q.empty()){
        int v = q.front();
        q.pop();
        for (auto u: edges[v])
            if (--indeg[u] == 0)
                q.push(u);
        res.push_back(v);
    }
    return res;
}


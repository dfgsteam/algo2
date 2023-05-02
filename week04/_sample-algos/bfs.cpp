#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1000001;
vector<int> edges[MAXN];
int used[MAXN];

void bfs(int s) {
    queue<int> q;
    used[s] = 1;
    q.push(s);
    while(!q.empty()) {
        int v = q.front();
        q.pop();
        for(auto u: edges[v]) 
            if(!used[u]) {
                used[u] = used[v] + 1;
                q.push(u);
            }
    }
}

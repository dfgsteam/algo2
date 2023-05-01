#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int MAXN =  100001;

int indeg[MAXN];
vector<int> edges[MAXN];

vector<int> kahn(int n) {
    vector<int> res;
    vector<int> q;
    for (int i = 1; i <= n; i++)
        if (!indeg[i])
            q.push_back(i);
    while (!q.empty()){
        int v = q.front();
        q.erase(q.begin());
        for (auto u: edges[v])
            if (--indeg[u] == 0)
                q.push_back(u);
        sort(q.begin(), q.end());
        res.push_back(v);
    }
    return res;
}

int main() {
    ll N, M, a, b;
    cin >> N >> M;
    for (ll i=0; i<M; i++) {
        cin >> a >> b;
        edges[a].push_back(b);
        indeg[b]++;
    }
    vector<int> kann = kahn(N);
    for (int i=0; i<kann.size(); i++) {
        cout << kann[i] << " ";
    }
}
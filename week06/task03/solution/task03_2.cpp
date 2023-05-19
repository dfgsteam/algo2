#include <bits/stdc++.h>
using namespace std;

const int MAXN = 100001;
vector<int> edges[MAXN];
int used[MAXN];

void dfs(int v) {
    used[v] = 1;
    for (auto u : edges[v]) {
        if (!used[u]) {
            dfs(u);
        }
    }
}

int main() {
    int N, M;
    cin >> N >> M;

    for (int i = 0; i < M; i++) {
        int a, b;
        cin >> a >> b;
        edges[a].push_back(b);
    }

    int k;
    while (cin >> k && k != 0) {
        memset(used, 0, sizeof(used));

        vector<int> rivers(k);
        for (int i = 0; i < k; i++) {
            cin >> rivers[i];
        }

        for (int i = 0; i < k; i++) {
            dfs(rivers[i]);
        }

        int meetingRiver = -1;
        for (int i = 1; i <= N; i++) {
            if (used[i]) {
                meetingRiver = i;
                break;
            }
        }

        if (meetingRiver != -1) {
            cout << meetingRiver << endl;
        } else {
            cout << "Schadstoffe treffen nicht aufeinander." << endl;
        }
    }

    return 0;
}

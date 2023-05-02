#include <bits/stdc++.h>
#include <ctype.h>
using namespace std;


const int MAXN = 100001;
vector<int> edges[MAXN];
int used[MAXN], tin[MAXN], tout[MAXN], timer = 1;

void add_to_edge(int v, int u) {
    edges[v].push_back(u);
}

void dfs(int v){
    used[v] = 1;
    tin[v] = timer++;
    for(auto u: edges[v])
        if(!used[u])
            dfs(u);
    tout[v] = timer++;
}
bool ancestor(int u, int v) {
    return tin[u] < tin[v] && tout[u] > tout[v];
}

int main() {
    int N;
    cin >> N;
    getchar();

    string names[N+1];

    string tmp;
    for (int i = 1; i <= N; i++) {
        getline(cin, tmp);
        names[i] = tmp;
    }

    int tmp1;
    for (int i = 1; i <= N; i++) {
        cin >> tmp1;
        add_to_edge(i, tmp1);
    }

    int num_of_cases;
    cin >> num_of_cases;
    int cases[num_of_cases+1][2];
    for (int i = 1; i <= num_of_cases; i++) {
        cin >> cases[i][0];
        cin >> cases[i][1];
    }

    

    for (int i = 1; i <= num_of_cases; i++) {
        fill(used, used+MAXN, 0);
        
        dfs(cases[i][0]);

        if (ancestor(cases[i][0], cases[i][1])) {
            cout << names[cases[i][0]] << " is an ancestor of " << names[cases[i][1]];
        }

        else {
            fill(used, used+MAXN, 0);
    
            dfs(cases[i][1]);
            if (ancestor(cases[i][1], cases[i][0])) {
                cout << names[cases[i][1]] << " is an ancestor of " << names[cases[i][0]];
            }

            else 
            cout << names[cases[i][0]] << " and " << names[cases[i][1]] << " are not related";
        }

        cout << "." << endl;
    }


    return 0;
}
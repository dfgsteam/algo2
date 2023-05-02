#include <bits/stdc++.h>
using namespace std;
const int MAXN = 100001;
vector<int> edges[MAXN];
int used[MAXN], tin[MAXN], tout[MAXN], timer = 1;

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

int main(){
    int names_counter, tmpi, tests, a, b;
    string tmps;
    cin >> names_counter;
    vector<string> names;

    for(int i = 0; i <= names_counter; i++){
        getline(cin, tmps);
        names.push_back(tmps);
    } 
    for(int i = 1; i <= names_counter; i++){
        cin >> tmpi;
        edges[tmpi].push_back(i);   
    }
    dfs(1);

    cin >> tests;
    for(int i = 0; i < tests; i++){
        cin >> a >> b;
        if(ancestor(a, b)){
            cout << names[b-1] << " is an ancestor of " << names[a-1] << "." << endl;        }
        else if(ancestor(b, a)) {
            cout << names[a-1] << " is an ancestor of " << names[b-1] <<"."<< endl;        }
        else{
            cout << names[a-1] << " and " << names[b-1] << " are not related." << endl;        }
    }

    return 0;
}


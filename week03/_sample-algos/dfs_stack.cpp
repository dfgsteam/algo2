#include <bits/stdc++.h>
using namespace std;
const int MAXN = 100001;
vector<int> edges[MAXN];
int used[MAXN];

void dfs(int v) {
    stack<int> st;
    st.push(v);
    while(!st.empty()) {
        int v = st.top();
        st.pop();
        if(used[v]) 
            continue;
        used[v] = 1;
        for(auto u: edges[v])
            st.push(u);
    }
}

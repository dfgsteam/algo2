#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1000001;
int parent[MAXN], ranka[MAXN];

void make_set(int v) {
  parent[v] = v;
  ranka[v] = 0;
}
int find_set(int v) {
  if (v == parent[v])
    return v;
  return parent[v] = find_set(parent[v]);
}
void union_sets(int a, int b) {
  a = find_set(a);
  b = find_set(b);
  if (a != b) {
    if (ranka[a] < ranka[b])
      swap(a, b);
    parent[b] = a;
    if (ranka[a] == ranka[b])
      ++ranka[a];
  }
}

bool checkAllConnected(int n) {
    int root = find_set(1);
    for (int i = 2; i <= n; i++)
        if (find_set(i) != root)
            return false;
    return true;
}


int main() {
    int n, m, a, b;
    cin >> n >> m;
    for (int i=0; i<n; i++)
        make_set(i);
    for (int i=0; i<m; i++) {
        cin >> a >> b;
        union_sets(a, b);
        if (i > n/2-1)
            if (checkAllConnected(n)) {
                cout << i+1 << endl;
                return 0;
            }
        
    }
    cout << "Build some more!" << endl;
    return 0;
}


#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1000001;
int parent[MAXN], rank[MAXN];

void make_set(int v) {
  parent[v] = v;
  rank[v] = 0;
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
    if (rank[a] < rank[b])
      swap(a, b);
    parent[b] = a;
    if (rank[a] == rank[b])
      ++rank[a];
  }
}


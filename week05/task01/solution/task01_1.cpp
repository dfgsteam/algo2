#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e6 + 5;

int n, m;
vector<int> a(MAXN), bit(MAXN);

void update(int i, int x) {
    while (i <= n) {
        bit[i] += x;
        i += i & -i;
    }
}

int query(int i) {
    int res = 0;
    while (i > 0) {
        res += bit[i];
        i -= i & -i;
    }
    return res;
}

int main() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        update(i, a[i]);
    }

    char c;
    int l, r;
    while (m--) {
        cin >> c >> l;
        if (c == 'q') {
            cin >> r;
            cout << query(r) - query(l - 1) << endl;
        } else {
            update(1, a[1]);
            for (int i = 1; i < n; i++) {
                a[i] = a[i + 1];
                update(i + 1, a[i]);
            }
            a[n] = a[1];
            update(n, a[n]);
        }
    }

    return 0;
}

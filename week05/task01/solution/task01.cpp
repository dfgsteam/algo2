#include <bits/stdc++.h>
using namespace std;

#include <bits/stdc++.h>
using namespace std;

int n, a[10000000], t[100000000];
int move_item = 0;
int items;

int sum(int r) {
    int res = 0;
    for (; r >= 0; r = (r & (r+1)) - 1)
        res += t[r];
    return res;
}

void inc(int i, int delta) {
    for (; i < n; i = (i | (i+1)))
        t[i] += delta;
}

int sum(int l, int r) {
    return sum(r) - sum(l-1);
}

void init(){
    for (int i = 0; i < n; i++)
        inc(i, a[i]);
}



int main() {
    int q, qn;
    cin >> q >> qn;
    items = q;
    vector<int> queries;
    int temp, pos_1, pos_2;
    long res;
    char temp2;
    for (int i=0; i<q; i++) {
        cin >> temp;
        a[i] = temp;
    }
    init();

    while (qn--) {
        cin >> temp2;
        if (temp2 == 'q') {
            cin >> pos_1 >> pos_2;
            cout << sum(pos_1+move_item, pos_2+move_item) << endl;
        } else {
            move_item++;
            for (int y=move_item+items; y>= move_item; y++)
                inc(y, a[y-1]);
            inc(move_item-1, a[move_item-1]*(-1));
        }   
    }
    return 0;
}
#include <stdio.h>
#define MAXN 1000000

int n, a[MAXN], d;
long long t[MAXN];

void inc(int i, int delta) {
    for (; i < n; i = (i | (i+1)))
        t[i] += delta;
}


void init(){
    for(int i = 0; i < MAXN; i++){
        t[i] = 0;
    }
    for (int i = 0; i < n; i++)
        inc(i, a[i]);
}

long long minisum(int r) {
    long long res = 0;
    for (; r >= 0; r = (r & (r+1)) - 1)
        res += t[r];
    return res;
}

long long sum(int l, int r) {
    //printf("sum(%d,%d)", l, r);
    return minisum(r) - minisum(l-1);
}

long long dsum(int l, int r){
        l += d;
        r += d;
        l %= n;
        r %= n;
        if(r < l) return sum(l, n-1) + sum(0, r);
        else return sum(l, r);
}


int main(){
        int m;
        d = 0;
        scanf("%d %d", &n, &m);
        for(int i = 0; i < n; i++){
                scanf("%d", &a[i]);
        }
        init();
        //printf("Values: ");
        //for(int i = 0; i < n; i++) printf("%d ", a[i]);
        //printf("\nFenwick: ");
        //for(int i = 0; i < n; i++) printf("%lld ", t[i]);
        //printf("\n");
        for(int i = 0; i < m; i++){
                char s[2];
                scanf("%s", s);
                if(s[0] == 'r') d++;
                else if(s[0] == 'q'){
                        int a, b;
                        scanf("%d %d", &a, &b);
                        printf("%lld\n", dsum(a-1, b-1));
                }else printf("Ungültiger Char: '%c'\n", s[0]);
        }
}

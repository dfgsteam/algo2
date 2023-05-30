#include <bits/stdc++.h>
#include <cmath>
#define ld long double
using namespace std;


double a, vp, vf;

ld minimize (ld l, ld r, ld eps, ld (* f) (ld)) {
    while (r - l > eps) {
        ld x1 = l + (r - l) / 3.0;
        ld x2 = l + 2.0 * (r - l) / 3.0;
        if (f (x1) > f (x2)) 
            l = x1;
        else 
            r = x2;
        }
    return l;
}

ld t (ld r) {
    return hypot(1-a, r)/vp + hypot(a, 1-r)/vf;
}

int main() {
    cin >> vp >> vf >> a;

    printf("%.9Lf\n",  minimize(0, 1, 1e-7, t));
}
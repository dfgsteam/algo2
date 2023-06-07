#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

typedef double lf ;
const lf EPSI = 1e-10;

struct point_only {
    lf x, y;
    point_only ( lf x , lf y ) : x ( x ) , y ( y ) {}
};

struct vec2 {
    lf x , y ;
    vec2 ( lf x , lf y ) : x ( x ) , y ( y ) {}
    vec2 & operator +=( const vec2 & o ) { x += o . x ; y += o . y ; return * this ; }
    vec2 & operator -=( const vec2 & o ) { x -= o . x ; y -= o . y ; return * this ; }
    vec2 & operator *=( const lf & o ) { x *= o ; y *= o ; return * this ; }
    vec2 & operator /=( const lf & o ) { x /= o ; y /= o ; return * this ; }
    friend vec2 operator +( vec2 a , const vec2 & b ) { return a += b ; }
    friend vec2 operator -( vec2 a , const vec2 & b ) { return a -= b ; }
    friend vec2 operator *( vec2 a , const lf & b ) { return a *= b ; }
    friend vec2 operator *( const lf &b , vec2 a ) { return a *= b ; }
    friend vec2 operator /( vec2 a , const lf & b ) { return a /= b ; }
};

lf dot (vec2 a, vec2 b) {
    return a.x * b.x + a.y * b.y;
}

lf cross (vec2 a, vec2 b) {
    return a.x * b.y - a.y * b.x;
}

lf norm_sqr ( vec2 a ) {
    return dot (a,a);
}
lf norm (vec2 a) {
    return sqrt(norm_sqr (a));
}

lf angle (vec2 a, vec2 b) {
    return acos (dot(a, b)/ (norm(a) * norm(b))) ;
}

lf full_angle (vec2 a, vec2 b) {
    return atan2(cross(a, b), dot(a, b));
}
bool angle_acute (vec2 a ,vec2 b) {
    return dot(a, b) > 0;
}
bool angle_obtuse(vec2 a, vec2 b) {
    return dot(a,b) < 0;
}

int main() {
    int n;
    lf a, b;
    cin >> n;
    bool inner = true;
    
    vector<point_only> points;
    vector<vec2> vecs;
    for (int i = 0; i < n; i++) {
        cin >> a >> b;
        points.push_back(point_only(a, b));
    }
    for (int i = 0; i<n; i++) {
        vecs.push_back(vec2(points[(i + 1) % n].x - points[i % n].x, points[(i + 1) % n].y - points[i % n].y));
    }

    for (int i = 0; i<n; i++) {
        lf radian = full_angle(vecs[i % n], vecs[(i + 1) % n]);
        lf degree = radian * 180 / M_PI;  // Umrechnung in Grad
        cout << i << " " << degree << endl;
        if (degree == 90 or degree == -90) {
            cout << "NO";
            return 0;
        } else if (!i) {
            inner = degree > 0 ? true : false;
        } else if (inner) {
            if (degree < 0) {
                inner = false;
            } else {
                cout << "NO" << endl;
                return 0; 
            }
        } else if (!inner) {
            if (degree > 0) {
                inner = true;
            } else {
            cout << "NO" << endl;
            return 0; 
            }
        } else {
            cout <<" in:" << inner << " d:" << degree << " i:" << i << endl;
        }
    }
    cout << "YES" << endl;
    return 0;
    
    //string result = isZigZagStar(polygon) ? "YES" : "NO";
    //cout << result << endl;
    
    return 0;
}
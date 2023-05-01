#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

/* bruche struct */
struct bruch {
    double nenner, zaehler;
    double value;
};

/* sort bruche conditions */
bool compareBruch(const bruch& a, const bruch& b) {
    if (a.value < b.value) {
        return true;
    } else if (a.value == b.value) {
        if (a.zaehler < b.zaehler) {
            return true;
        }
    }
    return false;
}


int main() {
    /* read nenner, zaehler amount */
    int nenner, zaehler;
    cin >> nenner >> zaehler;
    
    /* read nenner */
    vector<double> nenner_vector(nenner);
    for (int i=0; i<nenner_vector.size(); i++) {
        cin >> nenner_vector[i];
    }

    /* read zaehler */
    vector<double> zaehler_vector(zaehler);
    for (int i=0; i<zaehler_vector.size(); i++) {
        cin >> zaehler_vector[i];
    }

    /* create bruche */
    vector<bruch> bruche;
    for (int x=0; x<nenner_vector.size(); x++) {
        for (int y=0; y<zaehler_vector.size(); y++) {
            bruch b = {};
            b.nenner = nenner_vector[x];
            b.zaehler = zaehler_vector[y];
            b.value = b.nenner/b.zaehler;
            bruche.push_back(b);
        }
    }

    /* sort bruche */
    sort(bruche.begin(), bruche.end(), compareBruch);

    /* print bruch */
    for (int i=0; i<bruche.size(); i++) {
        cout << fixed << (int) bruche[i].nenner << "/" << (int) bruche[i].zaehler /*<<  ":" << bruche[i].value*/ << "\n";
    }
    /* return */
    return 0;
} 
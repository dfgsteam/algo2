#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
using namespace std;

int main() {
    // read n, m
    long n, m;
    cin >> n >> m;

    // read words
    vector<string> words(n);
    for (int i=0; i<n; i++) {
        cin >> words[i]; 
    }

    // read testcases
    char testcases[m][2];
    for (int i=0; i<m; i++) {
        cin >> testcases[i][0] >> testcases[i][1];
    }

    // sort array
    sort(words.begin(), words.end());
    auto doup = unique(words.begin(), words.end());
    words.erase(doup, words.end());
 
    // check testcases
    bool checked;
    for (int x=0; x<m; x++) {
        checked = false;
        for (int y=0; y<words.size(); y++) {
            if (words[y].front() == testcases[x][0] && words[y].back() == testcases[x][1]) {
                cout << words[y];
                if (y != words.size()-1) {
                    cout << " ";
                }
                checked = true;
            }
        }
        if (!checked) {
            cout << "Empty category!";
        }
        cout << "\n";
    }

    // return
    return 0;
} 
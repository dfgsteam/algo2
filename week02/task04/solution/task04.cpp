#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <string>
#include <cctype>
#include <map>

using namespace std;


int main() {
    // read n, m
    long n;
    cin >> n;

    // read words
    vector<string> words(n);
    for (int i=0; i<n; i++) {
        cin >> words[i]; 
    }

    // erase nonalpha
    for (int i=0; i<words.size(); i++) {
        words[i].erase(remove_if(words[i].begin(), words[i].end(), [](char x) { return !isalpha(x); }), words[i].end());
        transform(words[i].begin(), words[i].end(), words[i].begin(),[](unsigned char c){ return tolower(c); });
    }

    // sort array
    sort(words.begin(), words.end());
 
    // sort into a map
    map<string, int > result;
    for (string word : words) {
        if (result.find(word) == result.end()) {
            result[word] = 1; 
        } else {
            result[word]++; 
        }
    }

    for (auto item : result) {
        cout << item.first << " " << item.second << "\n";
    }

    // return
    return 0;
} 
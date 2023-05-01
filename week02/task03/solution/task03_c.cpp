#include <iostream>
#include <chrono>
#include <vector>
#include <algorithm>
#include <numeric>
#include <future>

using namespace std;
using namespace std::chrono;

// Funktion, die die Wörter prüft
void checkWords(const vector<string>& words, char testcase1, char testcase2) {
    bool checked = false;
    for (const auto& word : words) {
        if (word.front() == testcase1 && word.back() == testcase2) {
            cout << word << " ";
            checked = true;
        }
    }
    if (!checked) {
        cout << "Empty category!";
    }
    cout << "\n";
}

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
    words.erase(unique(words.begin(), words.end()), words.end());

    // Erstellen und Ausführen von Threads für jede Aufgabe
    vector<future<void>> futures;
    for (int i=0; i<m; i++) {
        futures.push_back(async(checkWords, words, testcases[i][0], testcases[i][1]));
    }

    // Warten auf Beendigung der Threads
    for (auto& future : futures) {
        future.get();
    }

    return 0;
}

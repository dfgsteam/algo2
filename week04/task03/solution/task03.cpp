#include <bits/stdc++.h>
#include <iterator>
#include <vector>
using namespace std;
const int MAXN = 4600;

vector<vector<int>> graph(MAXN);

int karger() {
    int n = graph.size();

    // Wiederhole den Algorithmus n*(n-1)/2 mal, um eine gute Approximation zu erzielen
    int min_cut = n*n;
    for (int i = 0; i < n*(n-1)/2; i++) {
        // Erstelle eine Kopie des Graphen
        vector<vector<int>> copy_graph(graph);

        // Führe den Kanten-Zusammenführungsprozess durch
        while (copy_graph.size() > 2) {
            // Wähle eine zufällige Kante aus
            int u = rand() % copy_graph.size();
            int v = rand() % copy_graph[u].size();
            int w = copy_graph[u][v];

            // Zusammenführen der Knoten u und w
            copy_graph[u].insert(copy_graph[u].end(), copy_graph[w].begin(), copy_graph[w].end());
            for (int j = 0; j < copy_graph[w].size(); j++) {
                int x = copy_graph[w][j];
                for (int k = 0; k < copy_graph[x].size(); k++) {
                    if (copy_graph[x][k] == w) {
                        copy_graph[x][k] = u;
                        break;
                    }
                }
            }

            // Entfernen von Selbstschleifen
            copy_graph[u].erase(remove(copy_graph[u].begin(), copy_graph[u].end(), u), copy_graph[u].end());
        }

        // Berechne die Anzahl der Kanten im Schnitt
        min_cut = min(min_cut, (int) copy_graph[0].size() - 1);
    }

    return min_cut;
}
    srand(time(NULL));

int main() {
    int n, m;
    cin >> n >> m;
    while (m--) {
        int u, v = 0;
        cin >> u >> v;
        cout << u << v;
        // cout << "ok";
        // graph[u--].push_back(v--);
        // graph[v--].push_back(u--);
        // cout << "ok";
    }
    cout << "ok";
    int min_cut = karger();
    cout << "Minimum cut: " << min_cut << endl;
    return 0;
}

#include <iostream>
#include <vector>

class UnionFind {
public:
    UnionFind(int n) {
        parent.resize(n);
        rank.resize(n, 0);
        for (int i = 0; i < n; i++) {
            parent[i] = i;
        }
    }

    int find(int x) {
        if (parent[x] != x) {
            parent[x] = find(parent[x]);
        }
        return parent[x];
    }

    bool unionSets(int x, int y) {
        int xRoot = find(x);
        int yRoot = find(y);

        if (xRoot == yRoot) {
            return false;
        }

        if (rank[xRoot] < rank[yRoot]) {
            parent[xRoot] = yRoot;
        } else if (rank[xRoot] > rank[yRoot]) {
            parent[yRoot] = xRoot;
        } else {
            parent[yRoot] = xRoot;
            rank[xRoot]++;
        }

        return true;
    }
};

std::string checkConnectivity(int n, int m, const std::vector<std::pair<int, int>>& roads) {
    UnionFind uf(n);
    int connected = 0;

    for (int i = 0; i < m; i++) {
        int a = roads[i].first - 1;
        int b = roads[i].second - 1;

        if (uf.unionSets(a, b)) {
            connected++;
            if (connected == n - 1) {
                return std::to_string(i + 1);
            }
        }
    }

    return "Build some more!";
}

int main() {
    int n, m;
    std::cin >> n >> m;

    std::vector<std::pair<int, int>> roads(m);
    for (int i = 0; i < m; i++) {
        std::cin >> roads[i].first >> roads[i].second;
    }

    std::string result = checkConnectivity(n, m, roads);
    std::cout << result << std::endl;

    return 0;
}

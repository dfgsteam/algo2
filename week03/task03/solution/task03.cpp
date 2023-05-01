#include <bits/stdc++.h>
using namespace std;

void add_edge(vector<int> roads[], int src, int dest) {
	roads[src].push_back(dest);
	roads[dest].push_back(src);
	}

bool BFS(vector<int> roads[], int src, int dest, int v, int pred[], int dist[]) {
	list<int> queue;

	bool visited[v];

	for (int i = 0; i < v; i++) {
		visited[i] = false;
		dist[i] = INT_MAX;
		pred[i] = -1;
	}

	visited[src] = true;
	dist[src] = 0;
	queue.push_back(src);

	while (!queue.empty()) {
		int u = queue.front();
		queue.pop_front();
		for (int i = 0; i < roads[u].size(); i++) {
			if (visited[roads[u][i]] == false) {
				visited[roads[u][i]] = true;
				dist[roads[u][i]] = dist[u] + 1;
				pred[roads[u][i]] = u;
				queue.push_back(roads[u][i]);

				if (roads[u][i] == dest)
					return true;
			}
		}
	}

	return false;
}

void printShortestDistance(vector<int> roads[], int s, int dest, int v) {
	int pred[v], dist[v];

	if (BFS(roads, s, dest, v, pred, dist) == false) {
		cout << "Given source and destination" << " are not connected";
		return;
	}

	vector<int> path;
	int crawl = dest;
	path.push_back(crawl);
	while (pred[crawl] != -1) {
		path.push_back(pred[crawl]);
		crawl = pred[crawl];
	}

	if (dist[dest] == 2) {
		cout << "2\n";
	} else {
		cout << dist[dest];
		for (int i = path.size() ; i >= 1; i--)
			cout << path[i] << " ";
	}
}

int main() {
	int intersections, roads_number, home_id, work_id;
	cin >> intersections >> roads_number;
	cin >> home_id >> work_id;



	vector<int> roads[intersections];

	for (int road=0; road<roads_number; road++) {
		int point_a, point_b;
		cin >> point_a >> point_b;
		point_a--;
		point_b--;
		add_edge(roads, point_a, point_b);
	}

	int source = 0, dest = 2;

	printShortestDistance(roads, home_id--, work_id--, intersections);
	return 0;
}

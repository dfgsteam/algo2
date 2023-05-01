//C++ program to find the Shortest Path in an Unweighted Graph
#include <bits/stdc++.h>
#include <ostream>
using namespace std;

class Graph{
public:
    int num_intersections;  // Anzahl an Punkten
    vector<int> *intersections; // Liste an Kanten

    Graph(int num_intersections){
        this->num_intersections = num_intersections;
        this->intersections = new vector<int>[num_intersections];
    }
        
    void addPoint(int u, int v){ // Punkt wird einem Graphen hinzugefügt
        intersections[u-1].push_back(v-1);
        intersections[v-1].push_back(u-1);
    }

    
    // BFS traversal that updates the dist and parent vector
    void BFS(int home, int work, vector<int> &dist, vector<int> &parent){
        vector<bool> is_visit(num_intersections, 0);      // is_visit sagt aus, ob ein Punkt besucht wurde
        queue<int> visit_queue; // queue to store nodes to be visited along the breadth
        visit_queue.push(home); // push home node to queue
        is_visit[home] = 1;// mark source node as visitedi
        while(!visit_queue.empty()){
            int visit_queue_size = visit_queue.size();  // traverse all nodes along the breadth
            while(visit_queue_size--){
                int node = visit_queue.front(); // extract the front node
                visit_queue.pop(); // pop the node
                is_visit[node] = 1; // mark it visited
                // traverse along the node's breadth
                for(int adjNode : this->intersections[node]){
                    if(!is_visit[adjNode]){ 
                        is_visit[adjNode] = 1; 
                        dist[adjNode] = dist[node] + 1;
                        parent[adjNode] = node;
                        visit_queue.push(adjNode);
                    }
                }
            }
        }
    }

    void findShortestPath(int home, int work){
        vector<int> dist(num_intersections, 0);
        vector<int> parent(num_intersections);
        for(int i=0;i<num_intersections;++i)
           parent[i] = i;
        BFS(home, work, dist, parent);
        //stack to store the path from workination to source
        // while backtracking using the parent vector
        stack<int> st;
        // backtracking loop
        while(parent[work]!=work){
            st.push(work);
            work = parent[work];
        }
        st.push(work);  // when the loop ends, it means we reach the source node   
        int Path_length = st.size(); //shortest path length
        // print the shortest path along with its length

        cout<<Path_length-2<<endl; 
        st.pop();
        while(st.size()>1){
            cout<<st.top()+1<<" ";
            st.pop();
        }
        cout<<endl;
    }

};

int main() {

    int num_intersections, num_roads, home, work;
    cin >> num_intersections >> num_roads;
    Graph G(num_intersections);
    cin >> home >> work;

    for (int road=0; road<num_roads; road++) {
        int point_a, point_b;
        cin >> point_a >> point_b;
        G.addPoint(point_a, point_b);
    }

    G.findShortestPath(home-1, work-1);
    return 0;
}
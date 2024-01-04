#include <iostream>
#include <vector>
#include <queue>
#include <climits>

using namespace std;

// Structure to represent an edge
struct Edge {
    int to, weight;
    Edge(int t, int w) : to(t), weight(w) {}
};

// Function to implement Prim's algorithm
void primMST(vector<vector<Edge>> &graph, int root) {
    int V = graph.size();
    vector<int> parent(V, -1);  // To store the parent of each vertex in the MST
    vector<int> key(V, INT_MAX); // To store the key values used in Prim's algorithm
    vector<bool> inMST(V, false); // To track if a vertex is already in the MST

    // Create a min-priority queue using a pair of key and vertex
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    // Initialize the priority queue and key values
    for (int u = 0; u < V; ++u) {
        pq.push({key[u], u});
    }

    // Set the key of the root to 0
    key[root] = 0;
    pq.push({key[root], root});

    while (!pq.empty()) {
        int u = pq.top().second;
        pq.pop();

        inMST[u] = true;

        for (const Edge &edge : graph[u]) {
            int v = edge.to;
            int weight = edge.weight;

            if (!inMST[v] && weight < key[v]) {
                parent[v] = u;
                key[v] = weight;
                pq.push({key[v], v});
            }
        }
    }

    // Output the MST by printing the parent values for vertices 1 to V-1
    for (int i = 1; i < V; ++i) {
        cout << parent[i] << endl;
    }
}

int main() {
    int V, E;
    cin >> V >> E;

    // Create an adjacency list to represent the graph
    vector<vector<Edge>> graph(V);

    // Read the edges and weights
    for (int i = 0; i < E; ++i) {
        int u, v, w;
        cin >> u >> v >> w;
        graph[u].emplace_back(v, w);
        graph[v].emplace_back(u, w); 
    }


    primMST(graph, 0);

    return 0;
}

// Write a Program to implement Prim’s algorithm to find minimum spanning tree of a user defined graph. Use Adjacency List to represent a graph.

#include <iostream>
using namespace std;

class Graph {
private:
    int adj[20][20];   // adjacency list stored as cost matrix
    int n;

public:
    Graph(int vertices) {
        n = vertices;

        // Initialize adjacency matrix with 0 (no edge)
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                adj[i][j] = 0;
    }

    void addEdge(int u, int v, int w) {
        adj[u][v] = w;
        adj[v][u] = w;   // undirected graph
    }

    // ---------- Prim's Algorithm ----------
    void prim(int start) {
        int key[20];        // Minimum edge weight to reach each node
        int parent[20];     // Store MST
        int visited[20];    // Marks included vertices

        for (int i = 0; i < n; i++) {
            key[i] = 9999;     // infinity
            visited[i] = 0;
        }

        key[start] = 0;
        parent[start] = -1;    // root of MST

        for (int count = 0; count < n - 1; count++) {

            // Step 1: Pick minimum key vertex
            int u = -1;
            int min = 9999;

            for (int i = 0; i < n; i++) {
                if (!visited[i] && key[i] < min) {
                    min = key[i];
                    u = i;
                }
            }

            visited[u] = 1;

            // Step 2: Update neighbors of u
            for (int v = 0; v < n; v++) {
                if (adj[u][v] != 0 && !visited[v] && adj[u][v] < key[v]) {
                    key[v] = adj[u][v];
                    parent[v] = u;
                }
            }
        }

        // Display MST
        cout << "\nMinimum Spanning Tree (Prim's Algorithm):\n";
        int total = 0;

        for (int i = 0; i < n; i++) {
            if (parent[i] != -1) {
                cout << parent[i] << " - " << i << "  (Weight = " << adj[i][parent[i]] << ")\n";
                total += adj[i][parent[i]];
            }
        }

        cout << "Total Minimum Cost = " << total << endl;
    }

    // Display adjacency matrix
    void display() {
        cout << "\nAdjacency Matrix (Cost Graph):\n";
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cout << adj[i][j] << " ";
            }
            cout << endl;
        }
    }
};

int main() {
    int n, e;
    cout << "Enter number of vertices: ";
    cin >> n;

    Graph g(n);

    cout << "Enter number of edges: ";
    cin >> e;

    cout << "Enter edges (u v weight):\n";
    for (int i = 0; i < e; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        g.addEdge(u, v, w);
    }

    g.display();

    int start;
    cout << "\nEnter starting vertex for Prim's Algorithm: ";
    cin >> start;

    g.prim(start);

    return 0;
}
// Write a Program to implement Kruskal’s algorithm to find the 
// Minimum Spanning Tree of a user defined graph. 
// Use Adjacency List represented as Cost Matrix.

#include <iostream>
using namespace std;

class Graph {
private:
    int adj[20][20];   // cost matrix (adjacency list representation)
    int n;

    int parent[20];    // DSU parent
    int rankArr[20];   // DSU rank

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

    // ------------ DSU: Find Parent ------------
    int findParent(int v) {
        if (parent[v] == v)
            return v;
        return parent[v] = findParent(parent[v]); // path compression
    }

    // ------------ DSU: Union Two Sets ----------
    void unionSet(int a, int b) {
        a = findParent(a);
        b = findParent(b);

        if (a != b) {
            if (rankArr[a] < rankArr[b])
                parent[a] = b;
            else if (rankArr[a] > rankArr[b])
                parent[b] = a;
            else {
                parent[b] = a;
                rankArr[a]++;
            }
        }
    }

    // ------------ Kruskal Algorithm ------------
    void kruskal() {

        // Step 1: Initialize DSU
        for (int i = 0; i < n; i++) {
            parent[i] = i;
            rankArr[i] = 0;
        }

        cout << "\nMinimum Spanning Tree (Kruskal's Algorithm):\n";

        int edgesAdded = 0;
        int totalCost = 0;

        // We need n - 1 edges in MST
        while (edgesAdded < n - 1) {
            int minCost = 9999;
            int a = -1, b = -1;

            // Step 2: Find minimum cost edge that does NOT form cycle
            for (int i = 0; i < n; i++) {
                for (int j = i + 1; j < n; j++) {
                    if (adj[i][j] != 0 && adj[i][j] < minCost &&
                        findParent(i) != findParent(j)) 
                    {
                        minCost = adj[i][j];
                        a = i;
                        b = j;
                    }
                }
            }

            // Step 3: Add this edge to MST
            unionSet(a, b);
            cout << a << " - " << b << " (Weight = " << minCost << ")\n";

            totalCost += minCost;
            edgesAdded++;
        }

        cout << "Total Minimum Cost = " << totalCost << endl;
    }

    // Display adjacency matrix
    void display() {
        cout << "\nAdjacency Matrix (Cost Graph):\n";
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++)
                cout << adj[i][j] << " ";
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

    cout << "\nRunning Kruskal's Algorithm...\n";
    g.kruskal();

    return 0;
}
// Write a Program to implement Dijkstra’s algorithm to find shortest distance between two nodes of a user defined graph. 
// Use Adjacency List to represent a graph.

#include <iostream>
using namespace std;

class Node {
public:
    int vertex;
    int weight;
    Node* next;

    Node(int v, int w) {
        vertex = v;
        weight = w;
        next = NULL;
    }
};

class Graph {
public:
    Node* adj[100];
    int n;

    Graph(int vertices) {
        n = vertices;
        for (int i = 0; i < n; i++)
            adj[i] = NULL;
    }

    void addEdge(int u, int v, int w) {
        Node* newNode = new Node(v, w);
        newNode->next = adj[u];
        adj[u] = newNode;

        // For UNDIRECTED graph — remove this if graph is directed
        newNode = new Node(u, w);
        newNode->next = adj[v];
        adj[v] = newNode;
    }

    int findMinVertex(int dist[], bool visited[]) {
        int minVertex = -1;

        for (int i = 0; i < n; i++) {
            if (!visited[i] && (minVertex == -1 || dist[i] < dist[minVertex])) {
                minVertex = i;
            }
        }
        return minVertex;
    }

    void dijkstra(int source) {
        int dist[100];
        bool visited[100];

        for (int i = 0; i < n; i++) {
            dist[i] = 999999;   // Infinity
            visited[i] = false;
        }

        dist[source] = 0;

        for (int i = 0; i < n - 1; i++) {

            int u = findMinVertex(dist, visited);
            visited[u] = true;

            Node* temp = adj[u];

            while (temp != NULL) {
                int v = temp->vertex;
                int w = temp->weight;

                if (!visited[v] && dist[u] + w < dist[v]) {
                    dist[v] = dist[u] + w;
                }

                temp = temp->next;
            }
        }

        // Print result
        cout << "\nShortest Distance from Source " << source << ":\n";
        for (int i = 0; i < n; i++) {
            cout << "Node " << i << " = " << dist[i] << endl;
        }
    }
};


int main() {
    int n, edges;
    cout << "Enter number of vertices: ";
    cin >> n;

    Graph g(n);

    cout << "Enter number of edges: ";
    cin >> edges;

    cout << "\nEnter edges (u v w):\n";
    for (int i = 0; i < edges; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        g.addEdge(u, v, w);
    }

    int source;
    cout << "\nEnter source node: ";
    cin >> source;

    g.dijkstra(source);

    return 0;
}
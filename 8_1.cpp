// Write a Program to accept a graph from a user and represent it with Adjacency Matrix and perform BFS and DFS traversals on it. without using any inbuilt libraries of cpp

#include <iostream>
using namespace std;

class Queue {
public:
    int arr[50];
    int front, rear;

    Queue() {
        front = 0;
        rear = 0;
    }

    // Insert element into queue
    void enqueue(int value) {
        arr[rear] = value;
        rear = rear + 1;
    }

    // Remove and return element from queue
    int dequeue() {
        int value = arr[front];
        front = front + 1;
        return value;
    }

    // Check if queue is empty
    bool isEmpty() {
        return front == rear;
    }
};

class Graph {
private:
    int adj[20][20];
    int visited[20];
    int n;

public:
    Graph(int vertices) {
        n = vertices;

        // Initialize adjacency matrix
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                adj[i][j] = 0;
    }

    void addEdge(int u, int v) {
        adj[u][v] = 1;
        adj[v][u] = 1;
    }

    // ---------------- DFS ----------------
    void DFSUtil(int v) {
        visited[v] = 1;
        cout << v << " ";

        for (int i = 0; i < n; i++) {
            if (adj[v][i] == 1 && visited[i] == 0) {
                DFSUtil(i);
            }
        }
    }

    void DFS(int start) {
        for (int i = 0; i < n; i++)
            visited[i] = 0;

        cout << "DFS Traversal: ";
        DFSUtil(start);
        cout << endl;
    }

    // ---------------- BFS using Queue Class ----------------
    void BFS(int start) {

        Queue q;

        // Reset visited array
        for (int i = 0; i < n; i++)
            visited[i] = 0;

        // Enqueue starting node
        q.enqueue(start);
        visited[start] = 1;

        cout << "BFS Traversal: ";

        while (!q.isEmpty()) {

            // Dequeue node
            int node = q.dequeue();
            cout << node << " ";

            // Visit all neighbors
            for (int i = 0; i < n; i++) {
                if (adj[node][i] == 1 && visited[i] == 0) {
                    visited[i] = 1;
                    q.enqueue(i);
                }
            }
        }

        cout << endl;
    }

    // Display adjacency matrix
    void displayMatrix() {
        cout << "\nAdjacency Matrix:\n";
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

    cout << "Enter edges (u v):\n";
    for (int i = 0; i < e; i++) {
        int u, v;
        cin >> u >> v;
        g.addEdge(u, v);
    }

    g.displayMatrix();

    int start;
    cout << "\nEnter starting vertex for DFS & BFS: ";
    cin >> start;

    g.DFS(start);
    g.BFS(start);

    return 0;
}
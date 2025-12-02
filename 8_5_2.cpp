#include <iostream>
using namespace std;

// ------------ Queue Class --------------
class Queue {
private:
    int arr[50];
    int front, rear;

public:
    Queue() {
        front = rear = 0;
    }

    void enqueue(int value) {
        arr[rear++] = value;
    }

    int dequeue() {
        return arr[front++];
    }

    bool isEmpty() {
        return front == rear;
    }
};

// ------------ Graph Class --------------
class Graph {
private:
    int adj[50][50];   // adjacency array
    int count[50];     // degree of each vertex
    int n;

public:
    Graph(int vertices) {
        n = vertices;
        for (int i = 0; i < n; i++) {
            count[i] = 0;
            for (int j = 0; j < n; j++)
                adj[i][j] = -1;
        }
    }

    void addEdge(int u, int v) {
        // Store v in adjacency list of u
        adj[u][count[u]] = v;
        count[u] = count[u] + 1;

        // Since graph is undirected, store u in adjacency list of v
        adj[v][count[v]] = u;
        count[v] = count[v] + 1;
    }

    // -------- BFS --------
    void BFS(int start) {
        int visited[50] = {0};
        Queue q;

        cout << "\nBFS Traversal: ";

        visited[start] = 1;
        q.enqueue(start);

        while (!q.isEmpty()) {
            int u = q.dequeue();
            cout << u << " ";

            for (int i = 0; i < count[u]; i++) {
                int v = adj[u][i];
                if (!visited[v]) {
                    visited[v] = 1;
                    q.enqueue(v);
                }
            }
        }
        cout << endl;
    }

    // -------- DFS --------
    void DFSUtil(int u, int visited[]) {
        visited[u] = 1;
        cout << u << " ";

        for (int i = 0; i < count[u]; i++) {
            int v = adj[u][i];
            if (!visited[v])
                DFSUtil(v, visited);
        }
    }

    void DFS(int start) {
        int visited[50] = {0};
        cout << "\nDFS Traversal: ";
        DFSUtil(start, visited);
        cout << endl;
    }

    // -------- Display --------
    void display() {
        cout << "\nAdjacency List (Array Format):\n";
        for (int i = 0; i < n; i++) {
            cout << i << " -> ";
            for (int j = 0; j < count[i]; j++)
                cout << adj[i][j] << " ";
            cout << endl;
        }
    }
};

// -------------- MAIN ----------------
int main() {
    int n, edges;
    cout << "Enter number of vertices: ";
    cin >> n;

    Graph g(n);

    cout << "Enter number of edges: ";
    cin >> edges;

    cout << "\nEnter edges (u v):\n";
    for (int i = 0; i < edges; i++) {
        int u, v;
        cin >> u >> v;
        g.addEdge(u, v);
    }

    g.display();

    int start;
    cout << "\nEnter starting vertex for BFS and DFS: ";
    cin >> start;

    g.BFS(start);
    g.DFS(start);

    return 0;
}

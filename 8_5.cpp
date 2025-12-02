// Write a Program to accept a graph from a user and represent it with Adjacency List and perform BFS and DFS traversals on it.
#include <iostream>
using namespace std;

class Node {
public:
    int vertex;
    Node* next;

    Node(int v) {
        vertex = v;
        next = NULL;
    }
};

// -------- Queue Class --------
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

// -------- Graph Class --------
class Graph {
private:
    Node* adj[50];
    int n;

public:
    Graph(int vertices) {
        n = vertices;
        for (int i = 0; i < n; i++)
            adj[i] = NULL;
    }

    void addEdge(int u, int v) {
        // Add v to u's list
        Node* newNode = new Node(v);
        newNode->next = adj[u];
        adj[u] = newNode;

        // Add u to v's list (undirected graph)
        newNode = new Node(u);
        newNode->next = adj[v];
        adj[v] = newNode;
    }

    // ---------------- BFS ----------------
    void BFS(int start) {
        int visited[50] = {0};
        Queue q;

        cout << "\nBFS Traversal: ";
        visited[start] = 1;
        q.enqueue(start);

        while (!q.isEmpty()) {
            int u = q.dequeue();
            cout << u << " ";

            Node* temp = adj[u];
            while (temp != NULL) {
                int v = temp->vertex;
                if (!visited[v]) {
                    visited[v] = 1;
                    q.enqueue(v);
                }
                temp = temp->next;
            }
        }
        cout << endl;
    }

    // ---------------- DFS ----------------
    void DFSUtil(int u, int visited[]) {
        visited[u] = 1;
        cout << u << " ";

        Node* temp = adj[u];
        while (temp != NULL) {
            int v = temp->vertex;
            if (!visited[v]) {
                DFSUtil(v, visited);
            }
            temp = temp->next;
        }
    }

    void DFS(int start) {
        int visited[50] = {0};
        cout << "\nDFS Traversal: ";
        DFSUtil(start, visited);
        cout << endl;
    }

    // Display adjacency list
    void display() {
        cout << "\nAdjacency List:\n";
        for (int i = 0; i < n; i++) {
            cout << i << " -> ";
            Node* temp = adj[i];
            while (temp != NULL) {
                cout << temp->vertex << " ";
                temp = temp->next;
            }
            cout << endl;
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

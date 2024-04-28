#include <iostream>
#include <bits/stdc++.h>
#include <omp.h>
using namespace std;

class Graph {
public:
    map<int, bool> visited;
    map<int, list<int>> adj;
    // function to add an edge to the graph
    void addEdge(int v, int w);
    // DFS traversal of the vertices reachable from v
    void DFS(int v);
};

void Graph::addEdge(int v, int w) {
    adj[v].push_back(w); // Add w to v's list.
}

void Graph::DFS(int v) {
    // Mark the current node as visited and print it
    visited[v] = true;
    cout << v << " ";
    // Recur for all the vertices adjacent to this vertex
    #pragma omp parallel for
    for (auto i = adj[v].begin(); i != adj[v].end(); ++i) {
        if (!visited[*i]) {
            DFS(*i);
        }
    }
}

int main() {
    omp_set_num_threads(4);
    int z;
    Graph g;
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 3);
    g.addEdge(2, 3);
    g.addEdge(3, 4);
    g.addEdge(3, 5);
    g.addEdge(2, 6);
    cout << "Enter the vertex to start the DFS traversal with: ";
    cin >> z;
    cout << "\nDepth First Traversal:\n";
    g.DFS(z);
    cout << endl;
    return 0;
}


/*

How to run 
g++ -std=c++11 -fopenmp HPC1.cpp -o HPC -pthread

./HPC
Enter the vertex to start the DFS traversal with: 2

Depth First Traversal:
2 3 4 5 6 

*/

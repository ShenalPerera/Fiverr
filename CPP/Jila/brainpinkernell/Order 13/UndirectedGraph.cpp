#include "UndirectedGraph.h"

UndirectedGraph::UndirectedGraph() {
    this->adjacencyMatrix = new int[DEFAULT_SIZE * DEFAULT_SIZE];
    for (int i = 0; i < DEFAULT_SIZE * DEFAULT_SIZE; i++) {
        adjacencyMatrix[i] = 0;
    }
    this->vertices = DEFAULT_SIZE;
}

UndirectedGraph::UndirectedGraph(int size) {
    this->adjacencyMatrix = new int[size * size];
    for (int i = 0; i < size * size; i++) {
        adjacencyMatrix[i] = 0;
    }
    this->vertices = size;
}

int UndirectedGraph::vertexCount() const {
    return vertices;
}

bool UndirectedGraph::edgeExists(int src, int dest) const {
    return adjacencyMatrix[src * vertices + dest] == 1;
}

bool UndirectedGraph::addEdge(int src, int dest) {
    if (adjacencyMatrix[src * vertices + dest] == 1 ){
        return false;
    }
    adjacencyMatrix[src * vertices + dest] = 1;
    adjacencyMatrix[dest * vertices + src] = 1;
    return true;
}

bool UndirectedGraph::removeEdge(int src, int dest) {
    if (adjacencyMatrix[src * vertices + dest] == 0 ){
        return false;
    }
    adjacencyMatrix[src * vertices + dest] = 0;
    adjacencyMatrix[dest * vertices + src] = 0;
    return true;
}

bool UndirectedGraph::graphConnected() const {
    bool* visited = new bool[vertices];
    for (int i = 0; i < vertices; i++) {
        visited[i] = false;
    }

    dfs(0, visited);

    for (int i = 0; i < vertices; i++) {
        if (!visited[i]) {
            delete[] visited;
            return false;
        }
    }

    delete[] visited;
    return true;
}

void UndirectedGraph::dfs(int v, bool *visited) const {
    visited[v] = true;

    for (int i = 0; i < vertices; i++) {
        if (adjacencyMatrix[v * vertices + i] && !visited[i]) {
            dfs(i, visited);
        }
    }
}
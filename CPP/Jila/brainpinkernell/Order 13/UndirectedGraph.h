#ifndef UNDIRECTEDGRAPH_H
#define UNDIRECTEDGRAPH_H

#define DEFAULT_SIZE 5
#include <vector>


using namespace std;
class UndirectedGraph {
public:
    UndirectedGraph();
    UndirectedGraph(int size);
    int vertexCount() const;
    bool edgeExists(int, int) const;
    bool addEdge(int, int);
    bool removeEdge(int, int);
    bool graphConnected() const;
    int * getAdjacencyMatrix() const;


private:
    int vertices;
    int * adjacencyMatrix;
    void dfs(int v, bool* visited) const;
};


#endif //UNDIRECTEDGRAPH_H

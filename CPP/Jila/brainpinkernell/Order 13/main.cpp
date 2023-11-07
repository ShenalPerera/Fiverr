#include <iostream>
#include "UndirectedGraph.h"

int main() {

    UndirectedGraph undirectedGraph(5);

    bool e1 = undirectedGraph.addEdge(0,1);
    bool e2 = undirectedGraph.addEdge(0,2);
    bool e3 = undirectedGraph.addEdge(0,4);
    bool e4 = undirectedGraph.addEdge(1,2);
    bool e5 = undirectedGraph.addEdge(1,3);
    bool e6 = undirectedGraph.addEdge(2,3);
    bool e7 = undirectedGraph.addEdge(2,4);
    bool e8 = undirectedGraph.addEdge(3,4);

    if (e1 && e2 && e3 && e4 && e5 && e6 && e7 && e8){
        cout << "Add edge    : Test   : Passed" << endl;
    }

    if (undirectedGraph.removeEdge(4,3)){
        cout << "Remove Edge : Test 1 : Passed" << endl;
    }

    if (!undirectedGraph.removeEdge(3,4)){
        cout << "Remove Edge : Test 2 : Passed" << endl;
    }

    if ( undirectedGraph.edgeExists(3,2)){
        cout << "Edge Exist  : Test   : Passed" << endl;
    }
    undirectedGraph.removeEdge(4,0);
    undirectedGraph.removeEdge(2,4);

    if (!undirectedGraph.graphConnected()){
        cout << "Connected   : Test 1  : Passed" << endl;
    }

    undirectedGraph.removeEdge(0,4);

    if (!undirectedGraph.graphConnected()){
        cout << "Connected   : Test 2  : Passed" << endl;
    }
    return 0;
}

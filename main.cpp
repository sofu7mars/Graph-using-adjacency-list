#include <iostream>
#include <vector>
#include <memory>
#include <set>
#include <list>
#include <stack>
#include <queue>
#include "graph.h"

using namespace std;



int main() {
    Graph g;
    Vertex v1, v2, v3, v4;
    vector<pair<int, int>> inputArr;
    inputArr.push_back({3, 100});
    inputArr.push_back({23, 150});

    v1.setID(1);
    v1.setName("London");
    v2.setID(23);
    v2.setName("Kyiv");
    v3.setID(3);
    v3.setName("Lublin");
    v4.setID(15);
    v4.setName("New York");

    g.addVertex(v1);
    g.addVertex(v2);
    g.addVertex(v3);
    g.addVertex(v4);

    g.addEdgeByID(1, 23, 200);
    g.addEdgeByID(1, 3, 100);
    g.addEdgeByID(23, 15, 400);
    g.addEdgeByID(1, 15, 1000);
    g.printGraph();
    g.updateEdgeByID(1, 23, 300);
    g.printGraph();

    g.deleteEdgeByID(1, 3);
    g.printGraph();

    g.deleteEdgeByID(1, 23);
    g.printGraph();

    // g.deleteVertexByID(1);
    // g.printGraph();

    g.updateVertexEdgesByID(1, inputArr);
    g.printGraph();

    g.updateVertexValuesByID(1, 88, "Lviv");
    g.printGraph();
    return 0;
}
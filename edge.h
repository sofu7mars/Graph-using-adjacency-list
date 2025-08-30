#define EDGE_H
#ifdef EDGE_H

#include <iostream>
#include <vector>
#include <memory>
#include <set>
#include <list>
#include <stack>
#include <queue>

using namespace std;

class Edge {
public:
    int destinationVertexID;
    int weight;
    Edge() {}
    Edge(int destVID, int w){
        destinationVertexID = destVID;
        weight = w;
    }
    void setEdgeValues(int destVID, int w){
        destinationVertexID = destVID;
        weight = w;
    }
    void setDestinationVretexID(int id) {
        destinationVertexID = id;
    }
    void setWeight(int w) {
        weight = w;
    }
    int getDestinationVertexID() {
        return destinationVertexID;
    }
    int getWeight() {
        return weight;
    }

};


#endif
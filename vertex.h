#define VERTEX_H
#ifdef VERTEX_H

#include "edge.h"

class Vertex {
public:
    int state_id;
    string state_name;
    list<Edge> edgeList;
    Vertex() {
        state_id = 0;
        state_name = "";
    }
    Vertex(int id, string name) {
        state_id = id;
        state_name = name;
    }
    int getStateID() {
        return state_id;
    }
    string getName() {
        return state_name;
    }
    void setID(int id) {
        state_id = id;
    }
    void setName(string name) {
        state_name = name;
    }
    list<Edge> getEdgeList() {
        return edgeList;
    }

};

#endif
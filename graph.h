#define GRAPH_H
#ifdef GRAPH_H

#include "vertex.h"

class Graph {
public:
    vector<Vertex> vertices;
    Graph() {}

    void addVertex(Vertex newVert) {
        bool check = checkIfVortexExistByID(newVert.getStateID());
        if (check == true) {
            cout << "Vertex already exists" << endl;   
            return;
        }
        vertices.push_back(newVert);
        cout << "Vertex added" << endl;   
    }
    bool checkIfVortexExistByID(int id) {
        for (int i = 0; i < vertices.size(); i++) {
            if (vertices.at(i).getStateID() == id) {
                // cout << vertices.at(i).getStateID() << ' ' << id << endl;
                return true;
            }
            // cout << vertices.at(i).getStateID() << ' ' << id << endl;
        }
        return false;
    }

    void printGraph() {
        cout << endl;
        for (auto& vert : vertices) {
            cout << vert.getName() << ' ' << '(' << vert.getStateID() << ')' << ": ";
            if (vert.edgeList.size() != 0) {
                cout << "[ ";
                for (auto it = vert.edgeList.begin(); it != vert.edgeList.end(); it++) {
                    if (next(it) != vert.edgeList.end()){
                        cout << '(' << it->getWeight() << ' ' << it->getDestinationVertexID() << ')' << " --> ";
                    } else {
                        cout << '(' << it->getWeight() << ' ' << it->getDestinationVertexID() << ')';

                    }
                }
                cout << " ]";
            } else {
                cout << "Vertex has no edges";
            }
            cout << endl;
        }
        cout << endl;
    }

    void addEdgeByID(int id1, int id2, int w) {
        // cout << "addEdgeByID function start" << endl;
        bool check1 = checkIfVortexExistByID(id1);
        bool check2 = checkIfVortexExistByID(id2);

        if (check1 && check2) {
            bool check3 = checkifEdgeExistByID(id1, id2);
            if (check3) {
                cout << "Edge already exists" << endl;
                return;
            }
            for (auto& vert : vertices) {
                if (vert.getStateID() == id1) {
                    Edge e(id2, w);
                    vert.edgeList.push_back(e);
                } else if( vert.getStateID() == id2) {
                    Edge e(id1, w);
                    vert.edgeList.push_back(e);
                }
            }
            cout << "Edge added Successfully" << endl;
        } else {
            cout << "Error" << '\n' << "id1: " << check1 << " | id2: " << check2 << endl;
        }
        // cout << "AddEdgeByID function end" << endl;
    }

    int getVertexIndexByID(int id) {
        for (int i{}; i < vertices.size(); i++) {
            if (vertices.at(i).getStateID() == id) {
                return i;
            }
        }
        return INT_MAX;
    }

    bool checkifEdgeExistByID(int id1, int id2) {
        int index = getVertexIndexByID(id1);
        for (auto& edge : vertices[index].edgeList) {
            if (edge.getDestinationVertexID() == id2) {
                return true;
            } 
        }
        return false;
    }
    
    void updateEdgeByID(int id1, int id2, int newW) {
        bool check1 = checkIfVortexExistByID(id1);
        bool check2 = checkIfVortexExistByID(id2);

        if (check1 && check2) {
            if (checkifEdgeExistByID(id1, id2)){
                for (auto& vert : vertices) {
                    if (vert.getStateID() == id1) {
                        for (auto& edge : vert.edgeList) {
                            if (edge.getDestinationVertexID() == id2) {
                                edge.setWeight(newW);
                            }
                        }
                    } else if (vert.getStateID() == id2) {
                        
                        for (auto& edge : vert.edgeList) {
                            if (edge.getDestinationVertexID() == id1) {
                                edge.setWeight(newW);
                            }
                        }
                    }
                }
            cout << "Edge value was successfully updated" << endl;
            } else {
                cout << "There is no edge" << endl;
            }
        }
    }

    void deleteEdgeByID(int id1, int id2) {
        bool check1 = checkIfVortexExistByID(id1);
        bool check2 = checkIfVortexExistByID(id2);
        if (check1 && check2) {
            if (checkifEdgeExistByID(id1, id2)) {
                for (auto& vert : vertices) {
                    if (vert.getStateID() == id1) {
                        for (auto it = vert.edgeList.begin(); it != vert.edgeList.end(); it++) {
                            if (it->getDestinationVertexID() == id2) {
                                // cout << "if is true " << it->getDestinationVertexID() << ' ' << id2 << endl;
                                vert.edgeList.erase(it);
                                break;
                            }
                        }
                    } else if (vert.getStateID() == id2) {
                        for (auto it = vert.edgeList.begin(); it != vert.edgeList.end(); it++) {
                            if (it->getDestinationVertexID() == id1) {
                                // cout << "if is true " << it->getDestinationVertexID() << ' ' << id1 << endl;
                                vert.edgeList.erase(it);
                                break;
                            }
                        }
                    }
                }
                cout << "Edge was successfully deleted" << endl;
            } else {
                cout << "There is no edge" << endl;
            }
        }
    }

    void deleteVertexByID(int id) {
        if (checkIfVortexExistByID(id)){
            for (auto it = vertices.begin(); it != vertices.end(); ) {
                if (it->getStateID() == id) {
                    it->edgeList.clear();
                    it = vertices.erase(it);
                } else {
                    for (auto eit = it->edgeList.begin(); eit != it->edgeList.end(); ) {
                        if (eit->getDestinationVertexID() == id) {
                            eit = it->edgeList.erase(eit);
                        } else {
                            ++eit;
                        }
                    }
                    ++it;
                }
            }
            cout << "Vertex was successfully deleted" << endl;
        } else cout << "There is no vertex by ID: " << id << endl;
    }
    
    void updateVertexEdgesByID(int id, const vector<pair<int, int>> &arr) {
        if (checkIfVortexExistByID(id)) {
            int verIndex = getVertexIndexByID(id);
            vertices.at(verIndex).edgeList.clear();
            for (auto& pair : arr) {
                if (checkIfVortexExistByID(pair.first)) {
                    addEdgeByID(id, pair.first, pair.second);
                } else cout << "There is no vertex with ID: " << pair.first << endl;
            }
            cout << "Vertex edges were updated successfully" << endl;
        } else cout << "Vertex does not exist" << endl;
    }

    void updateVertexValuesByID(int id, int newID, string newName) {
        if (checkIfVortexExistByID(id)) {
            for (auto& vert : vertices) {
                if (vert.getStateID() != id) {
                    for (auto& edge : vert.edgeList) {
                        if (edge.getDestinationVertexID() == id) {
                            edge.setDestinationVretexID(newID);
                            break;
                        }
                    }
                }
            }
            vertices.at(getVertexIndexByID(id)).setName(newName);
            vertices.at(getVertexIndexByID(id)).setID(newID);
            cout << "Vertex was successfully updated" << endl;
        } else cout << "Vertex does not exist" << endl;
    }

};

#endif
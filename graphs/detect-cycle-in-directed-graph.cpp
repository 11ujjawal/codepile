/* Detect cycle in directed graph - A DFS approach*/

#include <iostream>
#include <vector>
#include <list>

using namespace std;

class Graph {
    vector<list<int> > edges;
    bool detectCycleUtil(int startVertex, vector<bool>& visited, vector<bool>& visiting);
public:
    Graph(size_t vertices) : edges(vertices) {}
    inline void addEdge(int startVertex, int endVertex);
    bool detectCycle();

};

int main(void) {
    Graph g(4);
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 2);
    g.addEdge(2, 0);
    g.addEdge(2, 3);
    g.addEdge(3, 3);

    cout << g.detectCycle() << endl;

    return 0;
}

inline void Graph::addEdge(int startVertex, int endVertex) {
    edges[startVertex].push_back(endVertex);
}

/* detectCycle() iterates over all the start vertices and for each vertex,
 * traverses the graph in a depth first manner. Two structures are in place
 * to track the vertices. One structure, tracks the currently visiting vertices
 * and the other tracks all the vertices visited.
 *
  * This method invokes the detectCycleUtil() for each vertex from where a
  * node originates, and keeps track of the path in the visiting ds. All the
  * vertex ever visited are recorded in visited ds.
  */
bool Graph::detectCycle() {
    vector<bool> visited(edges.size(), false), visiting(edges.size(), false);

    for(vector<list<int> >::size_type startVertex = 0; startVertex != edges.size(); ++startVertex)
        if(detectCycleUtil(startVertex, visited, visiting))
            return true;

    return false;
}

/* detectCycleUtil() checks if the current path has a black edge or not i.e. if
 * the path leads to a vertes which has already been visited in the current
 * path. If any such path is encountered, it denotes a cycle.
 */
bool Graph::detectCycleUtil(int startVertex, vector<bool>& visited, vector<bool>& visiting) {
    if(!visited[startVertex]) {
        visited[startVertex] = visiting[startVertex] = true;

        for(list<int>::iterator endVertex = edges[startVertex].begin(); endVertex != edges[startVertex].end(); ++endVertex)
            /* A cycle can exist in the graph if any of the following two conditions are met -
             *
             * 1. The path leads to a vertex which is already a part of the current path
             * 2. The path has a vertex (currently not visited) and the paths originating
             * from that vertex has a cycle.
             */
            if((!visited[*endVertex] && detectCycleUtil(*endVertex, visited, visiting)) || visiting[*endVertex])
                return true;
    }

    /* Restore the visiting ds */
    visiting[startVertex] = false;
    return false;
}

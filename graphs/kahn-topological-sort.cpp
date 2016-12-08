/* Implement topological sort using Khan algorithm */

#include <iostream>
#include <queue>
#include <vector>
#include <list>

using namespace std;

class Graph {
    vector<list<int> > edges;
public:
    Graph(int vertices) : edges(vertices) {}
    inline void addEdge(int startVertex, int endVertex);
    void sort();
};

int main(void) {
    Graph g(6);
    g.addEdge(5, 2);
    g.addEdge(5, 0);
    g.addEdge(4, 0);
    g.addEdge(4, 1);
    g.addEdge(2, 3);
    g.addEdge(3, 1);

    g.sort();

    return 0;
}

inline void Graph::addEdge(int startVertex, int endVertex) {
    edges[startVertex].push_back(endVertex);
}

void Graph::sort() {
    vector<int> order, inDegree(edges.size(), 0);

    for(vector<list<int> >::iterator startVertex = edges.begin(); startVertex != edges.end(); ++startVertex)
        for(list<int>::iterator endVertex = (*startVertex).begin(); endVertex != (*startVertex).end(); ++endVertex)
            inDegree[*endVertex]++;

    queue<int> Q;
    int vertexCounter = 0;

    for(vector<int>::iterator iter = inDegree.begin(); iter != inDegree.end(); ++iter)
        if(*iter == 0)
            Q.push(distance(inDegree.begin(), iter));

    while(!Q.empty()) {
        int currVertex = Q.front();
        order.push_back(currVertex);
        Q.pop();

        for(list<int>::iterator iter = edges[currVertex].begin(); iter != edges[currVertex].end(); ++iter)
            if(--inDegree[*iter] == 0)
                Q.push(*iter);

        vertexCounter++;
    }

    if(vertexCounter != edges.size()) {
        cout << "The graph has a loop" << endl;
        return;
    }

    cout << "Topological Order: ";
    for(vector<int>::iterator ix = order.begin(); ix != order.end(); ++ix)
        cout << *ix << ' ';
    cout << endl;
}

/* Implement topological sort using tarjan's algorithm (Based on BFS) */

#include <iostream>
#include <stack>
#include <list>
#include <vector>

using namespace std;

class Graph {
    vector<list<int> > edges;
    void sortUtil(int startVertex, vector<bool>& visited, stack<int>& Stack);
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
    vector<bool> visited(edges.size(), false);
    stack<int> Stack;

    for(vector<list<int> >::size_type startVertex = 0; startVertex != edges.size(); ++startVertex)
        if(!visited[startVertex])
            sortUtil(startVertex, visited, Stack);

    while(!Stack.empty()) {
        cout << Stack.top() << ' ';
        Stack.pop();
    }

    cout << endl;
}

void Graph::sortUtil(int startVertex, vector<bool>& visited, stack<int>& Stack) {
    visited[startVertex] = true;

    for(list<int>::iterator endVertex = edges[startVertex].begin(); endVertex != edges[startVertex].end(); ++endVertex)
        if(!visited[*endVertex])
            sortUtil(*endVertex, visited, Stack);

    Stack.push(startVertex);
}

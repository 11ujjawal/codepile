/* Strongly Connected Components implementation using Kosaraju Algorithm */

#include <iostream>
#include <vector>
#include <list>
#include <stack>

using namespace std;

class Graph {
    vector<list<int> > edges;
    Graph getTranspose();
    void dfs(int startVertex, vector<bool>& visited);
    void dfsOrder(int startVertex, vector<bool>& visited, stack<int>& Stack);
public:
    Graph(size_t vertices) : edges(vertices) {}
    inline void addEdge(int startVertex, int endVertex);
    void printStronglyConnComp();
};

int main(void) {
    Graph g(5);

    g.addEdge(1, 0);
    g.addEdge(0, 2);
    g.addEdge(2, 1);
    g.addEdge(0, 3);
    g.addEdge(3, 4);

    g.printStronglyConnComp();

    return 0;
}

/* Print the strongly connected component of a graph */
void Graph::printStronglyConnComp() {
    vector<bool> visited(edges.size(), false);
    stack<int> Stack;

    for(vector<list<int> >::size_type startVertex = 0; startVertex != edges.size(); ++startVertex)
        if(!visited.at(startVertex))
            dfsOrder(startVertex, visited, Stack);

    Graph gTrans = getTranspose();

    fill(visited.begin(), visited.end(), false);

    while(!Stack.empty()) {
        int startVertex = Stack.top();
        Stack.pop();

        if(!visited.at(startVertex)) {
            gTrans.dfs(startVertex, visited);
            cout << endl;
        }
    }
}

/* Add edges in a graph */
inline void Graph::addEdge(int startVertex, int endVertex) {
    edges[startVertex].push_back(endVertex);
}

/* Get the dfs traversal in a stack */
void Graph::dfsOrder(int startVertex, vector<bool>& visited, stack<int>& Stack) {
    visited.at(startVertex) = true;

    for(list<int>::const_iterator endVertex = edges[startVertex].cbegin(); endVertex != edges[startVertex].cend(); ++endVertex)
        if(!visited[*endVertex])
            dfsOrder(*endVertex, visited, Stack);

    Stack.push(startVertex);
}

/* Fetch the transpose of a graph */
Graph Graph::getTranspose() {
    Graph gTrans(edges.size());

    for(vector<list<int> >::size_type startVertex = 0; startVertex != edges.size(); ++startVertex)
        for(list<int>::const_iterator endVertex = edges[startVertex].begin(); endVertex != edges[startVertex].end(); ++endVertex)
            gTrans.edges[*endVertex].push_back(startVertex);

    return gTrans;
}

/* DFS Traversal fromt the given start vertex */
void Graph::dfs(int startVertex, vector<bool>& visited) {
    visited.at(startVertex) = true;
    cout << startVertex << ' ';

    for(list<int>::const_iterator endVertex = edges[startVertex].cbegin(); endVertex != edges[startVertex].cend(); ++endVertex)
        if(!visited.at(*endVertex))
            dfs(*endVertex, visited);
}

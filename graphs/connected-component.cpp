#include <unordered_set>
#include <iostream>
#include <vector>
#include <stack>
#include <list>

using namespace std;

class Graph {
  private:
    vector<list<int> > edges;

  public:
    Graph(size_t vertices) : edges (vertices) {};
    inline list<int> getAdjacentVertex(int vertex);
    inline void addEdge(int startVertex, int endVertex);

    size_t getVertexCount() {
      return edges.size();
    }
};

inline list<int> Graph::getAdjacentVertex(int vertex) {
  return edges[vertex];
}

inline void Graph::addEdge(int startVertex, int endVertex) {
  edges[startVertex].push_back(endVertex);
  edges[endVertex].push_back(startVertex);
}

class ConnectedComponents {
  private:
    Graph g;
    vector<int> connected_index;

    void dfs(int startVertex, int count, unordered_set<int>& visited);

  public:
    ConnectedComponents(Graph G);
    bool isConnected(int vertexOne, int vertexTwo);
    size_t size();
    int id(int vertex);
};

ConnectedComponents::ConnectedComponents(Graph G) : g(G), connected_index(G.getVertexCount()) {
  unordered_set<int> visited;
  int count = 0;

  for (vector<int>::size_type vIndex = 0; vIndex != g.getVertexCount(); ++vIndex) {
    if (!connected_index[vIndex]) {
      dfs(vIndex, ++count, visited);
    }
  }
}

void ConnectedComponents::dfs(int startVertex, int count, unordered_set<int>& visited) {
  stack<int> Stack;
  Stack.push(startVertex);

  while(!Stack.empty()) {
    int currVertex = Stack.top();
    Stack.pop();

    if (visited.find(currVertex) != visited.end()) {
      continue;
    }

    visited.insert(currVertex);
    connected_index[currVertex] = count;
    for (const int v : g.getAdjacentVertex(currVertex)) {
      Stack.push(v);
    }

  }
}

int ConnectedComponents::id(int vertex) {
  return connected_index[vertex];
}

int main() {
  Graph g(13);
  g.addEdge(0, 1);
  g.addEdge(0, 2);
  g.addEdge(0, 5);
  g.addEdge(0, 6);
  g.addEdge(3, 4);
  g.addEdge(4, 6);
  g.addEdge(4, 5);
  g.addEdge(7, 8);
  g.addEdge(9, 10);
  g.addEdge(9, 11);
  g.addEdge(9, 12);
  g.addEdge(11, 12);

  ConnectedComponents cc(g);
  cout << cc.id(9) << endl;

  return 0;
}

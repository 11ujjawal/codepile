#include <unordered_map>
#include <unordered_set>
#include <iostream>
#include <vector>
#include <list>

using namespace std;

class Graph {
  private:
    unordered_map<char, list<char> > edges;

  public:
    Graph(size_t vertices) : edges (vertices) {};
    inline list<char> getAdjacentVertex(char vertex);
    inline void addEdge(char startVertex, char endVertex);
};

inline list<char> Graph::getAdjacentVertex(char vertex) {
  return edges[vertex];
}

inline void Graph::addEdge(char startVertex, char endVertex) {
  edges[startVertex].push_back(endVertex);
}

class GraphIterator {
  private:
    Graph g;
    char startVertex;

    bool checkPath(unordered_set<char>& visited, char vertex, char endVertex);
  
  public:
    GraphIterator(Graph G, char vertex) : g(G), startVertex(vertex) {}
    bool hasPathTo(char endVertex);
};

bool GraphIterator::hasPathTo(char endVertex) {
  unordered_set<char> visited;

  return checkPath(visited, startVertex, endVertex);
}

bool GraphIterator::checkPath(unordered_set<char>& visited, char vertex, char endVertex) {
  if (vertex == endVertex) {
    return true;
  }
  
  if (visited.find(vertex) == visited.end()) {
    visited.insert(vertex);
    
    for (const char v : g.getAdjacentVertex(vertex)) {
      if (checkPath(visited, v, endVertex)) {
        return true;
      }
    }
  }

  return false;
}

int main() {
  Graph g(4);
  g.addEdge('a', 'b');
  g.addEdge('a', 'c');
  g.addEdge('b', 'c');
  g.addEdge('c', 'a');
  g.addEdge('b', 'd');
  g.addEdge('d', 'd');

  GraphIterator gIter(g, 'a');
  cout << gIter.hasPathTo('d') << endl;

  return 0;
}

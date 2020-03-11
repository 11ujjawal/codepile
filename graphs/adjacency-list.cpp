#include <iostream>
#include <vector>
#include <list>

using namespace std;

class Graph {
  private:
    vector<list<int> > edges;

  public:
    Graph(size_t vertices) : edges (vertices) {};
    inline list<int> getAdjacentVertex(int vertex);
    inline void addEdge(int startVertex, int endVertex);
};

inline list<int> Graph::getAdjacentVertex(int vertex) {
  return edges[vertex];
}

inline void Graph::addEdge(int startVertex, int endVertex) {
  edges[startVertex].push_back(endVertex);
}

int main() {
  Graph g(4);
  g.addEdge(0, 1);
  g.addEdge(0, 2);
  g.addEdge(1, 2);
  g.addEdge(2, 0);
  g.addEdge(2, 3);
  g.addEdge(3, 3);

  for (const int vertex : g.getAdjacentVertex(0)) {
    cout << vertex << endl;
  }

  return 0;
}

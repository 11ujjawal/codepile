#include <iostream>
#include <vector>

using namespace std;

class Graph {
  private:
    vector<vector<int> > edges;

  public:
    Graph(size_t vertices) : edges (vertices, vector<int>(vertices)) {};
    vector<int> getAdjacentVertex(int vertex);
    inline void addEdge(int startVertex, int endVertex);
};

vector<int> Graph::getAdjacentVertex(int vertex) {
  vector<int> vertices;

  for (vector<int>::size_type index = 0; index != edges[vertex].size(); ++index) {
    if (edges[vertex][index]) {
      vertices.push_back(index);
    }
  }

  return vertices;
}

inline void Graph::addEdge(int startVertex, int endVertex) {
  edges[startVertex][endVertex] = 1;
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

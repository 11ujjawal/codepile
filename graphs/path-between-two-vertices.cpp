/* Check if a path exists between two vertices */

#include <iostream>
#include <vector>
#include <list>
#include <queue>

class Graph {
    std::vector<std::list<int> > edges;

public:
    Graph(std::size_t vertices) : edges(vertices) {}
    inline void addEdge(int startVertex, int endVertex);
    bool checkPath(int startVertex, int endVertex);
};

inline void Graph::addEdge(int startVertex, int endVertex) {
    edges[startVertex].push_back(endVertex);
}

bool Graph::checkPath(int startVertex, int endVertex) {
    std::vector<bool> visited(edges.size(), false);
    visited[startVertex] = true;

    std::queue<int> Queue;
    Queue.push(startVertex);

    while(!Queue.empty()) {
        int currStartVertex = Queue.front();
        Queue.pop();

        for(std::list<int>::const_iterator currEndVertex = edges[currStartVertex].cbegin(); currEndVertex != edges[currStartVertex].cend(); ++currEndVertex) {
            if(endVertex == *currEndVertex)
                return true;

            if(!visited[*currEndVertex]) {
                visited[*currEndVertex] = true;
                Queue.push(*currEndVertex);
            }
        }
    }

    return false;
}

int main(void) {
    Graph g(4);

    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 2);
    g.addEdge(2, 0);
    g.addEdge(2, 3);
    g.addEdge(3, 3);

    std::cout << "Path from vertex 1 to 3: " << g.checkPath(1, 3) << std::endl;
    std::cout << "Path from vertex 3 to 1: " << g.checkPath(3, 1) << std::endl;

    return 0;
}

/* Find the Minimum Spanning Tree using Kruskal's Algorithm */

#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
#include <unordered_map>

using namespace std;

/* DisjointSet DS - required for Kruskal Algorithm */
class DisjointSet {
    unordered_map<char, int> data, rank;

public:
    void MakeSet(const char elem) {
        if(data[elem])
            return;

        data[elem] = elem;
        rank[elem] = 0;
    }

    /* Find using path compression */
    char Find(const char elem) {
        if(data[elem] != elem)
            data[elem] = Find(data[elem]);

        return data[elem];
    }

    /* Union by rank */
    void Union(const char eOne, const char eTwo) {
        if(rank[eOne] > rank[eTwo])
            data[eTwo] = eOne;
        else if(rank[eTwo] > rank[eOne])
            data[eOne] = eTwo;
        else {
            data[eOne] = eTwo;
            rank[eTwo]++;
        }
    }
};

/* Alias for a graph edge - the first pair will be the edge (u, v) and the
 * second element of the pair is the weight.
 *
 * Template - pair < pair < startVertex, endVertex >, weight >
 */
using gEdge = pair<pair<char, char>, int>;

/* Graph implementation */
class Graph {
    vector<gEdge> edges;

public:
    Graph() {}
    inline void addEdge(char startVertex, char endVertex, int weight);
    void kruskal();
};

/* Ad new edge - each is of the form ((startVertex, endVertex), weight) */
inline void Graph::addEdge(char startVertex, char endVertex, int weight) {
    edges.push_back(make_pair(make_pair(startVertex, endVertex), weight));
}

/* Kruskal algorithm implementation */
void Graph::kruskal() {
    DisjointSet ds;

    for(vector<gEdge>::const_iterator edge = edges.begin(); edge != edges.end(); ++edge) {
        ds.MakeSet(edge->first.first);
        ds.MakeSet(edge->first.second);
    }

    /* Sort the edges based on the weight */
    sort(edges.begin(), edges.end(), [](gEdge eOne, gEdge eTwo) {return eOne.second < eTwo.second; });

    for(vector<gEdge>::const_iterator edge = edges.begin(); edge != edges.end(); ++edge) {
        char startVertex = edge->first.first;
        char endVertex = edge->first.second;

        char sVertexSet = ds.Find(startVertex);
        char eVertexSet = ds.Find(endVertex);

        if(sVertexSet != eVertexSet) {
            cout << startVertex << " - " << endVertex << endl;
            ds.Union(sVertexSet, eVertexSet);
        }
    }
}

int main(void) {
    Graph g;

    g.addEdge('a', 'b', 4);
    g.addEdge('b', 'c', 8);
    g.addEdge('c', 'd', 7);
    g.addEdge('d', 'e', 9);
    g.addEdge('e', 'f', 10);
    g.addEdge('g', 'f', 2);
    g.addEdge('h', 'g', 1);
    g.addEdge('a', 'h', 8);
    g.addEdge('h', 'b', 11);
    g.addEdge('h', 'i', 7);
    g.addEdge('i', 'c', 2);
    g.addEdge('f', 'c', 4);
    g.addEdge('i', 'g', 6);
    g.addEdge('d', 'f', 14);

    g.kruskal();

    return 0;
}

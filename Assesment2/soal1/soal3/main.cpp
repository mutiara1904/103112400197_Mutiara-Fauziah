#include "graph.h"

int main() {
    Graph G;
    createGraph(G);

    addNode(G, 'A');
    addNode(G, 'B');
    addNode(G, 'C');
    addNode(G, 'D');
    addNode(G, 'E');

    addEdge(G, 'A', 'B');
    addEdge(G, 'B', 'C');
    addEdge(G, 'B', 'E');
    addEdge(G, 'C', 'D');

    cout << "Membangun Jaringan Distribusi Vaksin\n";
    printGraph(G);

    analyze(G);

    return 0;
}

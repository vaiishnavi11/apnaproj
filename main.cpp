#include <iostream>
#include <string>
#include "Graph.h"
#include "Dijkstra.h"
#include "Result.h"

using namespace std;

int main() {
    Graph graph;

    graph.addEdge("A", "B", 4);
    graph.addEdge("A", "C", 2);
    graph.addEdge("B", "C", 1);
    graph.addEdge("B", "D", 5);
    graph.addEdge("C", "D", 8);
    graph.addEdge("C", "E", 10);
    graph.addEdge("D", "E", 2);

    string startNode = "A";
    string endNode = "E";

    cout << "Finding shortest route from " << startNode << " to " << endNode << "...\n\n";
    Result result = Dijkstra::findShortestPath(graph, startNode, endNode);
    
    result.print();

    return 0;
}
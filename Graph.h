#pragma once
#include <string>
#include <vector>
#include <unordered_map>
#include "Edge.h"

using namespace std;

class Graph {
private:
    unordered_map<string, vector<Edge>> adjList;

public:
    void addEdge(const string& source, const string& target, int weight) {
        adjList[source].push_back(Edge(target, weight));
        adjList[target].push_back(Edge(source, weight)); // Bidirectional shortcut
    }

    const vector<Edge>& getEdges(const string& node) {
        return adjList[node];
    }
};
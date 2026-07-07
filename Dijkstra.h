#pragma once
#include <queue>
#include <unordered_map>
#include <vector>
#include <string>
#include <algorithm>
#include "Graph.h"
#include "Result.h"

using namespace std;

class Dijkstra {
private:
    using NodeDistance = pair<int, string>;

public:
    static Result findShortestPath(Graph& graph, const string& source, const string& target) {
        unordered_map<string, int> distances;
        unordered_map<string, string> parentNodes;
        priority_queue<NodeDistance, vector<NodeDistance>, greater<NodeDistance>> pq;

        distances[source] = 0;
        pq.push({0, source});

        while (!pq.empty()) {
            auto [currentDist, u] = pq.top();
            pq.pop();

            if (u == target) break;

            if (distances.find(u) != distances.end() && currentDist > distances[u]) {
                continue;
            }

            for (const Edge& edge : graph.getEdges(u)) {
                string v = edge.getTarget();
                int weight = edge.getWeight();
                int newDist = currentDist + weight;

                if (distances.find(v) == distances.end() || newDist < distances[v]) {
                    distances[v] = newDist;
                    parentNodes[v] = u;
                    pq.push({newDist, v});
                }
            }
        }

        if (distances.find(target) == distances.end()) {
            return Result(-1, {});
        }

        vector<string> path;
        for (string at = target; !at.empty(); at = parentNodes[at]) {
            path.push_back(at);
        }
        reverse(path.begin(), path.end());

        return Result(distances[target], path);
    }
};
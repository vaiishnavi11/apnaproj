#pragma once
#include <string>
#include <vector>
#include <iostream>

using namespace std;

class Result {
private:
    int distance;
    vector<string> path;

public:
    Result(int distance, vector<string> path) : distance(distance), path(path) {}

    void print() const {
        if (distance == -1) {
            cout << "Target unreachable.\n";
            return;
        }
        cout << "Shortest Distance: " << distance << "\nPath: ";
        for (size_t i = 0; i < path.size(); ++i) {
            cout << path[i];
            if (i < path.size() - 1) cout << " -> ";
        }
        cout << "\n";
    }
};
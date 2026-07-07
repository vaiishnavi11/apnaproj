#pragma once
#include <string>

using namespace std;

class Edge {
private:
    string target;
    int weight;

public:
    Edge(string target, int weight) : target(target), weight(weight) {}
    string getTarget() const { return target; }
    int getWeight() const { return weight; }
};
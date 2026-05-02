#include <iostream>
#include <queue>
#include <unordered_map>
#include <vector>

// BFS Algorithm
// Uses Queue for nodes_to_visit, Unordered_Map for visited_nodes
// O (V + E)
//

using namespace std;

int shortPath(unordered_map<int, vector<int>> &graph, int start, int target) {
    unordered_map<int, int> visited_nodes = {{start, 0}}; // {{key, value}}
    unordered_map<int, int> parent = {{start, -1}}; // {{key, value}}

    queue<int> nodes_to_visit; //  = [start] queue does not support init
    nodes_to_visit.push(start);

    while(!nodes_to_visit.empty()) {

    // for(int i = 0; i < size(graph); i++) {
        auto n = nodes_to_visit.front();
        nodes_to_visit.pop();
        
        // auto n  = nodes_to_visit.pop();
        
        for (auto edge_node: graph[n]) {
            if (visited_nodes.find(edge_node) != visited_nodes.end()) continue;
            nodes_to_visit.push(edge_node);
            visited_nodes[edge_node] = visited_nodes[n] + 1;
            parent[edge_node] = n;

            if (edge_node == target) return visited_nodes[edge_node];
        }

    }

    return -1;

}


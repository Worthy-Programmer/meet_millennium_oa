#include <bits/stdc++.h>
using namespace std;

const int INF  = numeric_limits<int>::max();

// AL: {node, distance}
vector<int> dijkstra(const vector<vector<pair<int, int>>> &graph, int start_node) {

    auto n = ssize(graph);
    vector<int> distance(n, INF);

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq; // MIN HEAP: {dist, node}

    pq.push({0, start_node});
    distance[start_node] = 0;

    while(!pq.empty()) {
        auto [dist, node] = pq.top();
        pq.pop();
        if (dist > distance[node]) continue;

        for (auto [adj_node, edge_dist]: graph[node]) {
            auto new_dist = dist + edge_dist;
            if (distance[adj_node] > new_dist) {
                distance[adj_node] = new_dist;
                pq.push({new_dist, adj_node});
            }
        }
    }

    return distance;
}

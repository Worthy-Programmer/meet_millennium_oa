#include <bits/stdc++.h>
using namespace std;

// CHANGE: use vector<vector<int,int>> for GRAPH

pair<unordered_map<int, int>, unordered_map<int, int>> bfs(const unordered_map<int, vector<int>> &graph, int start_node) {
    unordered_map<int, int> distance;
    unordered_map<int, int> parent;

    for (auto [name, v]: graph) {
        distance[name] = -1;
        parent[name] = -1;
    }

    distance[start_node] = 0;
    queue<int> q;

    q.push(start_node);

    while(!q.empty()) {
        auto curr = q.front();
        q.pop();

        for (auto &n: graph.at(curr)) {
            if (distance.at(n) >= 0) continue;

            q.push(n);
            distance[n] = distance[curr] + 1;
            parent[n] = curr;
        }
    } 

    return make_pair(distance, parent);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    return 0;
}
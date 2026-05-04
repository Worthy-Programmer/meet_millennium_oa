#include <bits/stdc++.h>
using namespace std;


void dfs(const vector<vector<int>> &graph, int start_node) {
    auto n = graph.size();
    vector<int> parents(n, -1);
    vector<bool> visited(n, false);
    // vector<int> pre_number(n, 0);
    // vector<int> post_number(n, 0);

    stack<int> st;
    // int count  = 0;

    st.push(start_node);

    while(!st.empty()) {
        auto curr = st.top();
        st.pop();

        if(visited[curr]) continue;
        visited[curr] = true;

        for (auto v: graph[curr]) {
            if (visited[v]) continue;
            st.push(v); 
            parents[v] = curr;
        }
        // else { post_number[curr] = count; st.pop()}
        // count++;
    };

}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);


    return 0;
}
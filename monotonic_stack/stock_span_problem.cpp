// https://www.geeksforgeeks.org/dsa/the-stock-span-problem/

// Basically we have to find previous larger element -> So a decreasing stack starting from left

#include <bits/stdc++.h>
using namespace std;

vector<int> stock_span(const vector<int> &v) {
    auto n = v.size();
    stack<int> st;
    vector<int> result(n);

    for (auto i = 0; i < n; i++) {
        while (!st.empty() && v[st.top()] <= v[i]) st.pop(); // Strictly <= . Because I want my stack to be strictly decreasing

        if (!st.empty()) result[i] = i - st.top();
        else result[i] = i + 1;
        
        st.push(i);
    }

    return result;
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    vector<int> v {10, 4, 5, 90, 120, 80};
    auto r = stock_span(v);

    for (auto i: r) cout << i << ' ';
    cout << '\n';

    return 0;
}
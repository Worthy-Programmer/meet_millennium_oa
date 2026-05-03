// Largest Rectangular Area in a Histogram
// https://www.geeksforgeeks.org/dsa/largest-rectangular-area-in-a-histogram-using-stack/

// It's like say ith guy is in the rectangle, what's the largest rectangle that could be formed from that rectangle
// Then I'll find the maximum of it 

// It's like finding the next smaller and previous smaller, to find the rectangle height

#include <bits/stdc++.h>
using namespace std;

vector<int> nse(const vector<int> &v) { // Next Smaller ELement should have an increasing stack.
    auto n = ssize(v);
    stack<int> st;
    vector<int> res(n, n);

    for (auto i = n-1; i >= 0; i--) { // Forgot >=
        while(!st.empty() && v[st.top()] >= v[i]) st.pop();

        if (!st.empty()) res[i] = st.top();

        st.push(i);
    }
    return res;
}   

vector<int> pse(const vector<int> &v) { // Previous Smaller ELement should have an increasing stack.
    auto n = ssize(v);
    stack<int> st;
    vector<int> res(n, -1);

    for (auto i = 0; i < n; i++) {
        while(!st.empty() && v[st.top()] >= v[i]) st.pop();

        if (!st.empty()) res[i] = st.top();

        st.push(i);
    }
    return res;
}

int largest_rectangular_area(const vector<int> &v) {
    auto ns = nse(v);
    auto ps = pse(v);



    int max_area = -1;
    for (size_t i = 0; i < v.size(); i++) {
        // cout << v[i] << ' ' << ps[i] << ' ' << ns[i] << '\n';
        auto area  = (ns[i] -ps[i] - 1) * v[i];
        if (max_area < area) max_area = area;
    }

    return max_area;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    vector<int> v{60, 20, 50, 40, 10, 50, 60};
    cout << largest_rectangular_area(v) << '\n';
    return 0;
}
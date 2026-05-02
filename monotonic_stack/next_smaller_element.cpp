// https://www.geeksforgeeks.org/dsa/next-smaller-element/
// We will be using increasing monotonic stack
// [2 3 4] -> These are the numbers after 5
// I can say next number smallest number is 4, and add 5 to it


// Naive approach is double nested loop -> O(n**2)
// Increasing stack Approach-> Only including numbers from right side which are smaller than mine is just O(n) and space complexity O(n)


#include <bits/stdc++.h>
using namespace std;

vector<int> nse(const vector<int> &v) {

    auto n = ssize(v); // Signed Size -> So I can avoid underflow while I do 0 - 1, Introduced in C++20

    vector<int> result(n, -1);
    stack<int> st;

    // Iterating from right to left
    for (auto i = n - 1; i >= 0; i--) { // use int, not size_t, because size_t is unsigned, so 0-1 will be a high number
        // Adding Element to Increasing Monotonic Stack
        while (!st.empty() && st.top() >= v[i]) st.pop();

        // Whatever is remaining before adding current element is the next Smallest Element
        if (!st.empty()) result[i] = st.top();

        st.push(v[i]);
    }

    return result;
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    vector<int>s = {4, 8, 5, 2, 25};
    auto r = nse(s);

    for (auto i: r) cout << i << ' ';
    cout << endl;

    return 0;
}



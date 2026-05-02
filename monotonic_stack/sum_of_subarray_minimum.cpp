// Sum of Subarray Minimums
// https://www.geeksforgeeks.org/dsa/sum-of-minimum-elements-of-all-subarrays/#-1

 // [1, 2, 3, 4] 

 // Find the Previous Smaller Element as well as previous smaller element => The current element will be the smallest till we reach that range

 // previous smaller is same as next smaller -> Just reverse the array. Also we don't care about the array, so save the index instead

#include <bits/stdc++.h>
using namespace std;

vector <int> nse(const vector<int> &v) {
    auto n = ssize(v);
    vector<int> result_index(n);

    stack<int> st; // To store index

    // Increasing monotonic stack for next smallest element
    for (auto i = n-1; i >= 0; --i) {
        while (!st.empty() && v[st.top()] >= v[i]) st.pop(); // Ahhh Don't put if, put while

        if(!st.empty()) result_index[i] = st.top();
        else result_index[i] = n;

        st.push(i);
    }

    return result_index;
}

vector <int> pse(vector<int> v) {
    ranges::reverse(v);
    cout << '\n';
    auto n = ssize(v);
    auto reversed = nse(v); // NSE for Reversed V is PSE
    ranges::reverse(reversed); // Reverse the index once again to actually refer to ith index

    for (auto &r: reversed) r = n - 1 - r; // Change the index to refer to the reversed index
    return reversed;
}

int sum_of_subarray_min(const vector<int> &v) {
    auto ns = nse(v);
    auto ps = pse(v);



    int sum = 0;

    for (size_t i = 0; i < v.size(); i++) {
        cout << v[i] <<  ':' <<  ns[i] << ' ' << ps[i] << '\n';
        // auto maxlength = ns[i] - ps[i] - 1 ; // This contains any subarray even those which do not contain v[i]
        auto maxlength = (i - ns[i]) * (ps[i] - i);// THe subarray should contain v[i]
        assert(maxlength > 0);
        sum += v[i] * (maxlength);
    }

    return sum;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    vector<int> v {10, 20};
    cout << sum_of_subarray_min(v);
    return 0;
}

//2. The Final Word on the reverse Trick
// The reason the ranges::reverse trick is so hard to salvage for the overcounting problem is that handling duplicates requires asymmetrical strictness.

//     Your NSE needs a strict boundary: >= (pops duplicates).

//     Your PSE needs a non-strict boundary: > (keeps duplicates).

// When you reverse the array, run the exact same NSE function, and reverse it back, you are applying the strict >= boundary to both sides, which leads to the overcounting. In an OA, it is always faster and safer to just write the second for loop going left-to-right to find the PSE directly!
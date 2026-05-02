// Challenge 1: The Fault-Tolerant Deployment (Maximize the Minimum)

// Solution Method; Binary Search on Answers

// Background: You need to deploy K critical trading microservices across a linear data center.
// Problem: You are given an array of integers positions of length N, 
// representing the 1D coordinates of available server racks. 
// You must choose exactly K racks to place your microservices. 
// To minimize the risk of localized power failures taking down multiple services, 
// you want to maximize the minimum distance between any two microservices.

// Input: * vector<int> positions = {1, 2, 8, 4, 9}

//     int K = 3
//     Output: Return an integer representing the maximum minimum distance possible.
//     (Hint: If you place them at 1, 4, and 8, the distances are 3 and 4. The minimum distance is 3).

#include <bits/stdc++.h>
using namespace std;


// Greedy Method to just the next element with having d distance than the previously selected element
bool is_min_d_possible(const vector<int> &sorted_v, int d, int k) {
    int prev_value = sorted_v.front();
    int counter = 1;

    for (size_t i = 1; i < sorted_v.size(); ++i) {
        if ( (sorted_v[i] - prev_value) >= d) {
            counter++;
            prev_value = sorted_v[i];
            if (counter == k) return true;
        }
    }

    return false;
}


int binary_search_on_ans(vector<int> v, int k) {
    sort(v.begin(), v.end());

    auto dmax = v.back() - v.front();

    // Don't create the vector
    // vector<bool> a;

    // for (int d : views::iota(1, dmax + 1)) {
    //     a.push_back(is_min_d_possible(v, d, k));
    // }

    auto low = 0; auto high = dmax;

    auto bestanswer = -1;

    // Does binary search on answer because this virtual Array will be like [T, T, T, F, F, F, F]. We have to find the last True
    while (low <= high) {
        auto mid = low + (high - low) / 2;
        if (is_min_d_possible(v, mid, k)) {
            // We are successfully able to make a group. So now test it on right side
            low  = mid + 1;
            bestanswer = mid;
        }

        else {
            high = mid - 1;
        }
    }
    return bestanswer;
}



int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    vector<int> pos =  {1, 2, 8, 4, 9, 100, 200};
    int k = 3;

    auto ans = binary_search_on_ans(pos, k);
    cout << ans ;

    return 0;
}
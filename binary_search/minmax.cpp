// Challenge 2: The Data Pipeline Bottleneck (Minimize the Maximum)

// Background: You are processing a queue of daily trade logs. You must process them in the exact order they arrived.
// Problem: You are given an integer array logs where logs[i] is the size of the i-th log file in gigabytes, and an integer days, representing the deadline to process all logs. You have a distributed cluster that can process up to C gigabytes per day. If a log file takes the cluster over its daily capacity C, the remaining processing spills over to the next day, but you cannot split a single log file's processing across multiple days (so C must be at least as large as the largest log).
// Input:

//     vector<int> logs = {3, 2, 2, 4, 1, 4}

//     int days = 3
//     Output: Return the minimum daily capacity C required to process all logs within days days.

// My views: Again this is binary search on answer question. We  can rrange C from 3 to up max ( e, (sum // k ) ) to max(e) * length
// The answer on answer will be in form = > [False, False , False, True, True, True] We have to find the tipping point.


#include <bits/stdc++.h>
using namespace std;


// Greedy Checker
bool is_c_possible(const vector<int> &v, int c, int days) {
    int log_per_day = 0;
    int day_counter =  1;

    for (auto &e: v) {
        if( (log_per_day + e)  <= c) log_per_day += e;
        else  { log_per_day = e; day_counter++;}

        if (day_counter > days) return  false;
    }

    assert(day_counter <= days);
    return true;
}


// O( nlog (sum) )
int find_min_c(const vector<int> &v , int days) {
    long long s = accumulate(v.begin(), v.end(), 0LL); // OLL is 0 long long

    long long avg = round( s / (double) days);
    long long cmin = *max_element(v.begin(), v.end()); // THis function returns an iterator
    if (avg > cmin) cmin = avg;


    auto low = cmin; auto high = s;

    auto minc = -1;

    // Binary Search on MINC
    while (low <= high) {
        auto mid = low + floor ( (high - low) / 2 );  // Ohhhh it goes from False False to True. I initially made from True True to False
        if (is_c_possible(v, mid, days)) {
            high = mid - 1;
            minc = mid;
        } else low = mid + 1;
    }

    return minc;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    vector<int> logs = {3, 2, 2, 4, 1, 4, 10};
    int days = 3;

    // cout << is_c_possible(logs, 10 ,days);

    cout << "Minimum Capacity is: " << find_min_c(logs, days) << '\n';

    return 0;
}
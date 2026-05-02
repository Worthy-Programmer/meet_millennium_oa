#include <vector>
#include <unordered_map>
#include <priority_queue>
#include <pair>

using P =  pair<int, int> 


// Default of  pq is max_heap
bool greater_second(P a, P b) {
    return a.second > b.second;  // It orders such that the largest thing is at bottom
}


vector<int> top_k_frequent_element(vector<int> & elements, int k) {
    // O (n) for frequency map
    unordered_map<int, int> freq_map;
    for (auto e: elements) freq_map[e] ++;

    // O (nlogk) for pq to update itself

    // We have to maintain a min-heap
    priority_queue<P, vector<P>, greater_second> min_pq;

    min_pq

    //TODO: Don't forget to finish this later.

}
#include <algorithm>
#include <iostream>
#include <complex>
#include <vector>
#include <tuple>

using namespace std;
using CD = complex<double>;


bool bsearch() {
    vector<int> v = {1,3,4};
    int k = 4;


    return binary_search(v.begin(), v.end(), k);
}

bool custom_bsearch() {
    vector<CD> nums {{1,1}, {3,2}, {3,5}, {2,2}};

    auto compz = [] (const CD &a, const CD &b) {return make_tuple(abs(a), (double) a.real(), (double) a.imag()) < make_tuple((double)abs(b), (double) b.real(), (double) b.imag());};

    sort(nums.begin(), nums.end(), compz);

    return binary_search(nums.begin(), nums.end(), CD{3,2}, compz);

}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    if (custom_bsearch()) cout << "Custom b_search is working";
        return 0;

}

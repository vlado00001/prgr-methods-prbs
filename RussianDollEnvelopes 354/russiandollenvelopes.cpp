#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// increasing by width, firstly
// and decreasing by height, secondly,
// because 2 envelopes with the same width cannot be put in one another
bool cmpWidth(const vector<int> &a, const vector<int> &b) {
    if (a[0] == b[0]) {
        return a[1] > b[1];
    }
    return a[0] < b[0];
}

// sorting and searching LIS by height (not consecutively, but only by keeping the order)
// subsequence (not necessarily consecutively) != substring (elements are consecutive)
class Solution {
public:
    static unsigned int maxEnvelopes(vector<vector<int>> &envelopes) {
        sort(envelopes.begin(), envelopes.end(), cmpWidth);

        // LIS - longest increasing subsequence
        vector<int> lis;

        for (auto &e : envelopes) {
            int h = e[1];
            auto it = lower_bound(lis.begin(), lis.end(), h);

            if (it == lis.end()) {
                lis.push_back(h);
            } else {
                *it = h;
            }
        }
        return lis.size();
    }
};

int main() {
    vector<vector<int>> example{{5,4}, {1,1}, {1,1}, {6,7}, {6,6}, {9,8}, {7,3}};
    cout << Solution::maxEnvelopes(example) << endl;
}
#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    static int biggestsubset(const vector<int>& v) {
        int n = v.size();
        if (n == 0) return 0;
        if (n == 1) return v[0];
        int prev0 = 0; // max sum to i - 2
        int prev1 = v[0]; // max sum to i - 1
        for (int i = 1; i < n; i++) {
            int curr = max(prev0 + v[i], prev1);
            prev0 = prev1;
            prev1 = curr;
        }
        return prev1;
    }
};

int main() {
    vector<int> v = {2, 4, 6, 2, 5, 20, 20, 100, 96};
    cout << Solution::biggestsubset(v) << endl;
}
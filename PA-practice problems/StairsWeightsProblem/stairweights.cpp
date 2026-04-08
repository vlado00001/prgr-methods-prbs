#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    static int stairweights(vector <int> w) {
        int n = w.size();
        int first = w[0], second = w[1], third = w[2], res = 0;
        if (n == 1) {
            return first;
        } else if (n == 2) {
            return second;
        } else if (n == 3) {
            return third;
        }
        for (int i = 3; i < n; i++) {
            // if an aux vector were to be used, which is inefficient
            // dp[i] = min(min(w[i] + dp[i - 1], w[i] + dp[i - 2]), w[i] + dp[i - 3]);
            res = min(min(first, second), third) + w[i];
            first = second;
            second = third;
            third = res;
        }
        return res;
    }
};

int main() {
    Solution s;
    const vector <int> w = {3,4,7,2,9,11,35,2,1,55,3,2,78,6,34,2,445,1,425,12,12};
    cout << s.stairweights(w) << endl;
}
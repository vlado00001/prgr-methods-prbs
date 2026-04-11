#include <iostream>
#include <ostream>
#include <vector>
using namespace std;

class Solution {
public:
    static int minperfectsq(const int n) {
        if (n <= 0) return 0;
        vector<int> dp(n + 1, n);
        // dp[i] stores min number of squares to be summed to get i
        // initialised to n since the worst case is 1 summed n times.
        dp[0] = 0;
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j * j <= i; j++) {
                dp[i] = min(dp[i], dp[i - j * j] + 1);
            }
            printf("dp[%d] = %d\n", i, dp[i]);
        }
        return dp[n];
    }
};

int main() {
    int n = 1002461;
    cout << Solution::minperfectsq(n) << endl;
    return 0;
}
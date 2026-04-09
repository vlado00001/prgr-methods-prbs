#include <iostream>
#include <limits.h>
#include <unordered_map>

using namespace std;

class Solution {
public:
    static unordered_map<int, int> dp;
    static int reduceto1(int n) {
        if (n <= 1) return 0;
        if (n == 2 || n == 3) return 1;
        // has this subproblem been calculated before?
        if (dp.count(n)) return dp[n];

        int res = min((n % 2) + 1 + reduceto1(n / 2),
                      (n % 3) + 1 + reduceto1(n / 3));
        // keeps the answer
        return dp[n] = res;
    }
};

unordered_map<int, int> Solution::dp;

int main() {
    const int n = 10;
    int s = Solution::reduceto1(n);
}
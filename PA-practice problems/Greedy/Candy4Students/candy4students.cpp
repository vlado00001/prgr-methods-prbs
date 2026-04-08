#include <iostream>
#include <numeric>
#include <vector>

using namespace std;

class Solution {
public:
    static int candy4students(vector <float> v) {
        const int n = static_cast<int>(v.size());
        if (!n) {
            return 0;
        }
        vector<int> dp (n, 1);
        for (int i = 1; i < n; i++) {
            if (v[i] > v[i - 1]) {  // ascending
                dp[i] = dp[i - 1] + 1;
            } else if (v[i] == v[i - 1]) {  // stagnating
                dp[i] = dp[i - 1];
            } else {    // descending
                dp[i] = 1;  // starting from the minimum allowed, we back-propagate
                            // until the candy rule is met for the first time
                for (int j = i - 1; j >= 0 && v[j] > v[j + 1] && dp[j] <= dp[j + 1]; j--) {
                    dp[j] = dp[j + 1] + 1;
                }
            }
        }
        for (int i = 0; i < dp.size(); i++) {
            cout << dp[i] << " ";
        }
        cout << endl;
        return accumulate(dp.begin(), dp.end(), 0);
    }
    static int candy4students_efficient(vector <float> v) {
        const int n = static_cast<int>(v.size());
        if (!n) {
            return 0;
        }
        vector<int> dp (n, 1);
        for (int i = 1; i < n; i++) {
            if (v[i] > v[i - 1]) {
                dp[i] = dp[i - 1] + 1;
            } else if (v[i] == v[i - 1]) {
                dp[i] = dp[i - 1];
            }
        }
        for (int i = n - 2; i >= 0; i--) {
            // max is used to not override peaks
            if (v[i] > v[i + 1]) {
                dp[i] = max(dp[i], dp[i + 1] + 1);
            } else if (v[i] == v[i + 1]) {
                dp[i] = max(dp[i], dp[i + 1]);
            }
        }
        return accumulate(dp.begin(), dp.end(), 0);
    }
};

int main() {
    Solution s;
    const vector <float> v = {4,5,2,9,10,10,2,3,4,6,1,1,5,3,7,2,6,7,5,4,3};
                            //1 2 1 2  3  3 1 2 3 4 1 1 2 1 2 1 2 4 3 2 1 (descending sequences may require cascade-modifying)
    cout << s.candy4students(v) << endl;
    cout << s.candy4students_efficient(v) << endl;
}
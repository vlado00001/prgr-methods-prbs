#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

struct Activity {
    string name;
    int price;
    int rank;
};

class Solution {
public:
    static int activitybudget(int n, int B, vector<Activity>& activities) {
        vector<int> dp(B + 1, 0);

        for (int i = 0; i < n; i++) {
            for (int j = B; j >= activities[i].price; j--) {
                dp[j] = max(dp[j], dp[j - activities[i].price] + activities[i].rank);
            }
        }
        return dp[B];
    }
};

int main() {
    int n = 7;
    int B = 7;
    vector<Activity> activities = {
        {"Parasailing", 3, 1},
        {"Snorkeling", 5, 2},
        {"City Tour", 4, 3},
        {"Zip Line", 2, 4},
        {"Activity 5", 10, 5},
        {"Activity 6", 4, 6},
        {"Activity 7", 15, 7}
    };

    int maxRank = Solution::activitybudget(n, B, activities);

    cout << maxRank << endl;

    return 0;
}
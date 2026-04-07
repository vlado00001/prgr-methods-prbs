#include <cstring>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    static void knight_spath(const vector<vector<int>> &M) {
        const int lines = M.size(), cols = M[0].size();
        int dp[lines][cols];
        memset(dp, 0, sizeof(dp));
        dp[0][0] = M[0][0];
        for (int i = 1; i < lines; i++) {
            dp[i][0] = dp[i - 1][0] + M[i][0];
        }
        for (int j = 1; j < cols; j++) {
            dp[0][j] = dp[0][j - 1] + M[0][j];
        }
        for (int i = 1; i < lines; i++) {
            for (int j = 1; j < cols; j++) {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]) + M[i][j];
            }
        }
        // displays dp
        for (int i = 0; i < lines; i++) {
            for (int j = 0; j < cols; j++) {
                printf("%d ", dp[i][j]);
            }
            printf("\n");
        }
        // displays rewards sum
        printf("\n");
        cout << dp[lines - 1][cols - 1] << endl << endl;
        // displays path taken
        int i = 0, j = 0;
        while (i < lines && j < cols) {
            printf("(%d, %d): %d\n", i, j, dp[i][j]);
            if (i == lines - 1) {
                j++;
            } else if (j == cols - 1) {
                i++;
            } else if (dp[i][j + 1] >= dp[i + 1][j]) {
                j++;
            } else {
                i++;
            }
        }
    }
};

int main() {
    Solution s;
    const vector<vector<int>> M = {
        { 5,  2,  1,  1},
        { 1, 10,  1,  1},
        { 1,  1, 20,  1},
        { 1,  1,  1, 10}
    };
    s.knight_spath(M);
    return 0;
}
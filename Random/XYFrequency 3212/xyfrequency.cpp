#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    static int numberOfSubmatrices(vector<vector<char>>& grid) {
        vector<vector<int>>  prefix(grid.size(), vector<int> (grid[0].size(), 0));
        vector<vector<bool>> hasX(grid.size(), vector<bool>(grid[0].size(), false));
        int cnt = 0;

        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[0].size(); j++) {
                int curr = grid[i][j] == 'X' ?  1 :
                           grid[i][j] == 'Y' ? -1 : 0;

                hasX[i][j] = (grid[i][j] == 'X');

                prefix[i][j] = curr;
                if (i > 0) {
                    prefix[i][j] += prefix[i-1][j];
                    hasX[i][j]   = hasX[i][j] || hasX[i-1][j];
                }
                if (j > 0) {
                    prefix[i][j] += prefix[i][j-1];
                    hasX[i][j]   = hasX[i][j] || hasX[i][j-1];
                }
                if (i > 0 && j > 0) {
                    prefix[i][j] -= prefix[i-1][j-1];
                    hasX[i][j]   = hasX[i][j] || hasX[i-1][j-1];
                }

                if (hasX[i][j] && prefix[i][j] == 0)
                    cnt++;
            }
        }
        return cnt;
    }
};

int main() {
    vector<vector<char>> grid1 = {
        {'X', 'X'},
        {'X', 'X'}
    };
    cout << "Test 1: " << Solution::numberOfSubmatrices(grid1) << " (expected 0)" << endl;

    vector<vector<char>> grid2 = {{'X'}};
    cout << "Test 2: " << Solution::numberOfSubmatrices(grid2) << " (expected 0)" << endl;

    vector<vector<char>> grid3 = {{'Y'}};
    cout << "Test 3: " << Solution::numberOfSubmatrices(grid3) << " (expected 0)" << endl;

    vector<vector<char>> grid4 = {{'X', 'Y'}};
    cout << "Test 4: " << Solution::numberOfSubmatrices(grid4) << " (expected 1)" << endl;

    return 0;
}
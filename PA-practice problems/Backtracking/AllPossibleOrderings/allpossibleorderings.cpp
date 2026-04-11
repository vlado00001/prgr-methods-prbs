#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    static void back(int k, int n, vector<int>& res, u_int64_t& count) {
        // printing the found sequence
        if (k == 0) {
            count++;
            for (int x : res) cout << x << " ";
            cout << endl;
            return;
        }

        // tries placing number k in all possible positions
        for (int i = 0; i < 2 * n - k - 1; ++i) {
            int j = i + k + 1;  // the position for the twin
            if (res[i] == 0 && res[j] == 0) {

                // only allows the first occurrence of n to be in the first half
                if (k == n && i >= n) continue;

                res[i] = res[j] = k; // place
                back(k - 1, n, res, count);
                res[i] = res[j] = 0; // backtrack
            }
        }
    }

    static u_int64_t orderings(int n) {
        // it is mathematically demonstrated that solutions exist only if n % 4 == 0 or 3
        if (n % 4 != 0 && n % 4 != 3) return 0;

        vector<int> res(2 * n, 0);
        u_int64_t count = 0;
        back(n, n, res, count);
        return count;
    }
};

int main() {
    int n = 13;
    cout << "n = " << n << ":\n" << Solution::orderings(n) << " solutions" << endl;
    return 0;
}
#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    static unsigned long x_occurrences(const vector<int> &v, int x) {
        unsigned long n = v.size();
        if (!n) return 0;
        // binary search for smallest element bigger than x
        unsigned long low = 0, high = n - 1, lower_bound = n, upper_bound = n;
        while (low <= high) {
            unsigned long mid = low + (high - low) / 2;
            if (v[mid] <= x) {
                if (mid == n - 1) break;
                low = mid + 1;
            } else if (v[mid] > x) {
                upper_bound = mid;
                if (!mid) break;
                high = mid - 1;
            }
        }

        // binary search for first element >= x
        low = 0, high = v.size() - 1;
        while (low <= high) {
            unsigned long mid = low + (high - low) / 2;
            if (v[mid] >= x) {
                lower_bound = mid;
                if (!mid) break;
                high = mid - 1;
            } else if (v[mid] < x) {
                if (mid == n - 1) break;
                low = mid + 1;
            }
        }
        // if lower_bound is n at the end, x is higher than all elements in the vector
        //
        if (lower_bound == n || v[lower_bound] != x) return 0;
        return upper_bound - lower_bound;
    }
};

int main() {
    Solution s;
    vector<int> v = {1,2,3,5,6,6,7,7,7,7,9,10,11};
    cout << s.x_occurrences(v, 0) << endl;
}
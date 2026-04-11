#include <algorithm>
#include <iostream>
#include <stdint.h>
#include <vector>

using namespace std;

class Solution {
public:
    static int closestto0(vector<int>& v) {
        u_int32_t n = v.size();
        if (n == 0) return 0;
        if (n == 1) return v[0];
        // not rotated
        if (v[0] < v[n - 1]) return v[0];
        u_int32_t low = 0, high = n - 1;
        // binary search
        while (low < high) {
            u_int32_t mid = low + (high - low) / 2;
            if (v[mid] > v[high]) {
                low = mid + 1;
            } else {
                high = mid;
            }
        }

        return v[low];
    }
};

int main() {
    vector<int> v = {5,6,7,8,10,1,2,3};
    cout << Solution::closestto0(v) << endl;
}
#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    static int mountainpeak(vector <int> h) {
        int first = 0, last = h.size() - 1;
        while (first <= last) {
            int mid = first + (last - first) / 2;
            if (h[mid] <= h[mid + 1]) {
                first = mid + 1;
            } else if (h[mid] > h[mid + 1]) {
                last = mid - 1;
            }
        }
        return h[first];
    }
};

int main() {
    Solution s;
    const vector <int> h = {0,1,2,4,9,11,12,13,14,15,11,6,1};
    cout << s.mountainpeak(h) << endl;
}
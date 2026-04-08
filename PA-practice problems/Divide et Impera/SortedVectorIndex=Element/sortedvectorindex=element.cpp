#include <iostream>
#include <vector>

using namespace std;

class Solution {
    public:
    static int sortedVectorIndex(vector <int> v) {
        int left = 0, right = v.size() - 1, result = -1;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (v[mid] == mid) {
                result = mid; // found
            //    right = mid - 1;  // this, with line 15 commented ensures the first element to satisfy the condition is returned
                return result;
            }
            else if (v[mid] < mid)
                left = mid + 1; // the index may be to the right
            else if (v[mid] > mid)
                right = mid - 1;    // the index may be to the left
        }
        return result;
    }
};

int main() {
    Solution s;
    const vector <int> v = {0,1,2,4,9,11,12,13,14};
    cout << s.sortedVectorIndex(v) << endl;
}
#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    static string lexicographical_reduction(string s, int k) {
        for (int j = 0; j < k; j++) {
            if (s.empty()) break;
            int i = 0, n = s.length();
            while (i < n - 1 && s[i] <= s[i + 1]) {
                i++;
            }
            s.erase(i, 1);
        }
        return s;
    }
};

int main() {
    string s = "4321501756083561015";
    int k = 9;
    cout << Solution::lexicographical_reduction(s, k) << endl;
}
#include <algorithm>
#include <iostream>
#include <stdint.h>
#include <vector>

using namespace std;

class Solution {
public:
    static string common_substr(string s1, string s2) {
        int length = min(s1.length(), s2.length());
        for (int i = 0; i < length; i++) {
            if (s1[i] != s2[i]) return s1.substr(0, i);
        }
        return s1.substr(0, length);
    }

    static string divetimp(const vector<string>& s, int low, int high) {
        // Base case: one string
        if (low == high) return s[low];

        int mid = low + (high - low) / 2;

        string leftLCP = divetimp(s, low, mid);
        string rightLCP = divetimp(s, mid + 1, high);

        return common_substr(leftLCP, rightLCP);
    }

    static string lcp(vector<string>& s) {
        if (s.empty()) return "";
        return divetimp(s, 0, s.size() - 1);
    }

};

int main() {
    vector<string> strs = {"antidepressants", "antioxidant", "anticipation", "ant"};
    cout << Solution::lcp(strs) << endl;
}
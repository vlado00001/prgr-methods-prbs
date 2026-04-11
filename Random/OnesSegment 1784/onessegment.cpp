#include <iostream>

using namespace std;

class Solution {
public:
    static bool checkOnesSegment(string s) {
        short count = 0;
        for (int i = 1; i < s.length(); i++) {
            if (s[i] != s[i - 1]) {
                count++;
                if (count > 2) {
                    return false;
                }
            }
        }
        if (s[s.length()] != s[s.length() - 1]) {
            count++;
        }
        return count > 2 ? false : true;
    }
};
int main() {
    cout << Solution::checkOnesSegment("1001") << endl;
    return 0;
}

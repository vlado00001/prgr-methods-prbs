#include <iostream>

using namespace std;

class Solution {
public:
    static bool nimgame(int n) {
        // starting player loses if n is a multiple of 4
        return n % 4 != 0;
    }
};

int main() {
    int n = 400;
    cout << boolalpha << "Win? " << Solution::nimgame(n)
    << " (if the opponent plays optimally)" << endl;
}
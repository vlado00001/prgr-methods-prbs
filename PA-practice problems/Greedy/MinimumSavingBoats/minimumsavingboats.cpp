#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    static int minimumsavingboats(vector <int> w, int W) {
        int res = 0, n = w.size();
        sort(w.begin(), w.end());
        for (int i = 0, j = n - 1; i <= j;) {
            if (i == j) {
                res++;
                return res;
            }
            if (w[i] + w[j] <= W) {
                res++;
                i++;
                j--;
            } else if (w[i] + w[j] > W) {
                res++;
                j--;
            }
        }
        return res;
    }
};

int main() {
    Solution s;
    const vector <int> w = {30,55,75,22,10,78,130,34,67,33,11,127};
                        //   10 11 22 30 33 34 55 67 75 78 127 130  sorted
    int W = 140;
    cout << s.minimumsavingboats(w, W) << endl;
}
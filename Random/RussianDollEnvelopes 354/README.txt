You are given a 2D array of integers envelopes where envelopes[i] = [wi, hi] represents the width and the height of an envelope.
One envelope can fit into another if and only if both the width and height of one envelope are greater than the other envelope's width and height.
Return the maximum number of envelopes you can Russian doll (i.e., put one inside the other).
Note: You cannot rotate an envelope.

Example 1:
Input: envelopes = [[5,4],[6,4],[6,7],[2,3]]
Output: 3
Explanation: The maximum number of envelopes you can Russian doll is 3 ([2,3] => [5,4] => [6,7]).

Example 2:
Input: envelopes = [[1,1],[1,1],[1,1]]
Output: 1

Constraints:
    1 <= envelopes.length <= 10^5
    envelopes[i].length == 2
    1 <= w_i, h_i <= 10^5

Solution:

Sorts envelopes ascending by width, descending by height on ties. The descending height ensures two envelopes with the same width can never both appear in an increasing subsequence on height.
Then sorts LIS on the heights only. The length of lis at the end is the answer.

Complexity:

T: O(nlogn) + n * O(logn) // sort function + n binary searches in the for loop
S: O(n) // lis holds at most n values
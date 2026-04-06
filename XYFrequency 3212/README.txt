Given a 2D character matrix grid, where grid[i][j] is either 'X', 'Y', or '.', return the number of that contain:
- grid[0][0]
- an equal frequency of 'X' and 'Y'.
- at least one 'X'.

Example 1:

Input: grid = [["X","Y","."],["Y",".","."]]
Output: 3

Example 2:

Input: grid = [["X","X"],["X","Y"]]
Output: 0
Explanation:
No submatrix has an equal frequency of 'X' and 'Y'.

Example 3:

Input: grid = [[".","."],[".","."]]
Output: 0
Explanation:
No submatrix has at least one 'X'.

Constraints:
1 <= grid.length, grid[i].length <= 1000
grid[i][j] is either 'X', 'Y', or '.'.

Solution:

A value is assigned to each cell: X=+1, Y=-1, .=0. A submatrix starting at (0,0) and ending at (i,j) has equal X and Y counts if and only if its total sum is 0. A 2D prefix sum is built so that prefix[i][j] holds the sum of the entire rectangle from (0,0) to (i,j), using the standard inclusion-exclusion formula to avoid double-counting:
    prefix[i][j] = curr + prefix[i-1][j] + prefix[i][j-1] - prefix[i-1][j-1]

Simultaneously hasX[i][j] keeps a prefix OR that tracks whether any X exists anywhere in that same rectangle, propagated the same way.
At each cell, if prefix[i][j] == 0 and hasX[i][j] == true, the submatrix ending at (i,j) satisfies both conditions, the counter is incremented.

Complexity:

T: O(m*n)  // single pass
S: O(m*n)  // two auxiliary grids

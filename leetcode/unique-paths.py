"""
A robot is located at the top-left corner of a m x n grid (marked 'Start' in the diagram below).

The robot can only move either down or right at any point in time. The robot is trying to reach the bottom-right corner of the grid (marked 'Finish' in the diagram below).

How many possible unique paths are there?

Example 1:
Input: m = 3, n = 2
Output: 3
Explanation: From the top-left corner, there are a total of 3 ways to reach the bottom-right corner:
1. Right -> Down -> Down
2. Down -> Down -> Right
3. Down -> Right -> Down

Example 2:
Input: m = 7, n = 3
Output: 28
"""

def uniquePaths(self, m: int, n: int) -> int:
    if m == 1 or n == 1:
        return 1

    cache = [ [0 for _ in range(n)] for _ in range(m) ]

    # there is only 1 way to reach any cell on the same row or same col as that of start
    for i in range(n):
        cache[0][i] = 1
    for i in range(m):
        cache[i][0] = 1

    # observe patter: steps to reach any cell = steps to reach UP cell + steps to reach LEFT cell 
    for i in range(1, m):
        for j in range(1, n):
            cache[i][j] = cache[i-1][j] + cache[i][j-1]

    return cache[m-1][n-1]
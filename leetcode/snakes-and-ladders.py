"""
You are given an n x n integer matrix board where the cells are labeled from 1 to n^2 in a Boustrophedon style starting 
from the bottom left of the board (i.e. board[n - 1][0]) and alternating direction each row.

You start on square 1 of the board. In each move, starting from square curr, do the following:

Choose a destination square next with a label in the range [curr + 1, min(curr + 6, n^2)].
This choice simulates the result of a standard 6-sided die roll: i.e., there are always at most 6 destinations, 
regardless of the size of the board.

If next has a snake or ladder, you must move to the destination of that snake or ladder. Otherwise, you move to next.
The game ends when you reach the square n^2.

A board square on row r and column c has a snake or ladder if board[r][c] != -1. The destination of that snake or 
ladder is board[r][c]. Squares 1 and n^2 are not the starting points of any snake or ladder.

Note that you only take a snake or ladder at most once per dice roll. If the destination to a snake or ladder is the 
start of another snake or ladder, you do not follow the subsequent snake or ladder.

For example, suppose the board is [[-1,4],[-1,3]], and on the first move, your destination square is 2. You follow the
ladder to square 3, but do not follow the subsequent ladder to 4.
Return the least number of dice rolls required to reach the square n^2. If it is not possible to reach the square, return -1.

Example 1:
Input: board = [[-1,-1,-1,-1,-1,-1],[-1,-1,-1,-1,-1,-1],[-1,-1,-1,-1,-1,-1],[-1,35,-1,-1,13,-1],[-1,-1,-1,-1,-1,-1],
[-1,15,-1,-1,-1,-1]]
Output: 4
Explanation: 
In the beginning, you start at square 1 (at row 5, column 0).
You decide to move to square 2 and must take the ladder to square 15.
You then decide to move to square 17 and must take the snake to square 13.
You then decide to move to square 14 and must take the ladder to square 35.
You then decide to move to square 36, ending the game.
This is the lowest possible number of moves to reach the last square, so return 4.

Example 2:
Input: board = [[-1,-1],[-1,3]]
Output: 1
"""

    def snakesAndLadders(self, board: List[List[int]]) -> int:

        q = deque()

        n = len(board)
        n_sq = n * n
        reverse = False
        start, end, inc = -1, -1, -1

        flattened_board = []

        # Flattened board is a 1D array to map index to board square
        # Eg: Index 0 -> Board Square 1, Index 1 -> Board Square 2, etc.
        for row in range (n-1, -1, -1):
            if not reverse:
                start, end, inc = 0, n, 1
            else:  
                start, end, inc = n-1, -1, -1

            reverse = not reverse

            for col in range(start, end, inc):
                flattened_board.append(board[row][col])

        visited = [False] * (n_sq + 1)

        q.append((1, 0))
        while q:

            cell, steps = q.popleft()

            if cell == n_sq:
                return steps

            for i in range(cell+1, min(cell+7, n_sq+1)):
                # If the cell has a snake or ladder, we move to the destination
                if flattened_board[i-1] != -1 and not visited[flattened_board[i-1]]:
                    q.append( (flattened_board[i-1], steps+1) )
                    visited[flattened_board[i-1]] = True

                elif flattened_board[i-1] == -1:
                    if not visited[i]:
                        q.append( (i, steps + 1) )
                        visited[i] = True 

        return -1
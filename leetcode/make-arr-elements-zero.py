"""
3354. Make Array Elements Equal to Zero

You are given an integer array nums.

Start by selecting a starting position curr such that nums[curr] == 0, and choose a movement direction of either left or right.

After that, you repeat the following process:

If curr is out of the range [0, n - 1], this process ends.

If nums[curr] == 0, move in the current direction by incrementing curr if you are moving right, or decrementing curr if you are moving left.
Else if nums[curr] > 0:

Decrement nums[curr] by 1.
Reverse your movement direction (left becomes right and vice versa).
Take a step in your new direction.

A selection of the initial position curr and movement direction is considered valid if every element in nums becomes 0 by the end of the process.

Return the number of possible valid selections.

 

Example 1:

Input: nums = [1,0,2,0,3]
Output: 2

Explanation:

The only possible valid selections are the following:

Choose curr = 3, and a movement direction to the left.
[1,0,2,0,3] -> [1,0,2,0,3] -> [1,0,1,0,3] -> [1,0,1,0,3] -> [1,0,1,0,2] -> [1,0,1,0,2] -> [1,0,0,0,2] -> [1,0,0,0,2] -> [1,0,0,0,1] -> [1,0,0,0,1] -> [1,0,0,0,1] -> [1,0,0,0,1] -> [0,0,0,0,1] -> [0,0,0,0,1] -> [0,0,0,0,1] -> [0,0,0,0,1] -> [0,0,0,0,0].
Choose curr = 3, and a movement direction to the right.
[1,0,2,0,3] -> [1,0,2,0,3] -> [1,0,2,0,2] -> [1,0,2,0,2] -> [1,0,1,0,2] -> [1,0,1,0,2] -> [1,0,1,0,1] -> [1,0,1,0,1] -> [1,0,0,0,1] -> [1,0,0,0,1] -> [1,0,0,0,0] -> [1,0,0,0,0] -> [1,0,0,0,0] -> [1,0,0,0,0] -> [0,0,0,0,0].

Example 2:

Input: nums = [2,3,4,0,4,1,0]
Output: 0

Explanation:

There are no possible valid selections.
"""


# Brute force by simulating the process for each possible initial position and movement direction
def countValidSelections(self, nums: List[int]) -> int:

    result = 0

    def _simulate(arr: List[int], dir: int, curr: int):

        while 0 <= curr < len(nums):

            curr += dir
            
            if curr < 0 or curr >= len(arr):
                return

            if arr[curr] > 0:
                arr[curr] -= 1
                dir *= -1



    for i, elem in enumerate(nums):

        if elem == 0:

            nums_temp = copy.deepcopy(nums) 
            
            _simulate(nums_temp, -1, i)
            if all(x == 0 for x in nums_temp):
                result += 1

            nums_temp = copy.deepcopy(nums)

            _simulate(nums_temp, 1, i)
            if all(x == 0 for x in nums_temp):
                result += 1
    
    return result

    
    
## Optimized solution : O (N)
def countValidSelections(self, nums: List[int]) -> int:

    n = len(nums)
    left_sum = [0] * n
     right_sum = [0] * n

    l_sum = 0
    r_sum  = 0
    result = 0

    # Calculate the left and right sum arrays
    for i, elem in enumerate(nums):
        l_sum += elem
        left_sum[i] = l_sum

        r_sum += nums[n - i - 1]
        right_sum[n - i - 1] = r_sum

    for i, elem in enumerate(nums):
        
        if elem == 0:
            # If the absolute difference between the left and right sum is 1, 
            # then there is only 1 valid direction to move in (towards the side with the larger sum).
            if abs( left_sum[i] - right_sum[i] ) == 1:
                result += 1

            elif left_sum[i] == right_sum[i]:
                result += 2

    return result
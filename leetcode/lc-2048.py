"""
2048. Next Greater Numerically Balanced Number

An integer x is numerically balanced if for every digit d in the number x, there are exactly d occurrences of that digit in x.

Given an integer n, return the smallest numerically balanced number strictly greater than n.

 
Example 1:

Input: n = 1
Output: 22

Explanation: 
22 is numerically balanced since:
- The digit 2 occurs 2 times. 
It is also the smallest numerically balanced number strictly greater than 1.

Example 2:

Input: n = 1000
Output: 1333

Explanation: 
1333 is numerically balanced since:
- The digit 1 occurs 1 time.
- The digit 3 occurs 3 times. 
It is also the smallest numerically balanced number strictly greater than 1000.
Note that 1022 cannot be the answer because 0 appeared more than 0 times.
"""

# Try with generate-all-unique-permutations method
def nextBeautifulNumber(self, n: int) -> int:

    for num in range(n+1, 1224445):

        digit_freq_map = Counter( str(num) )
        is_valid = True

        for key in digit_freq_map:
            if digit_freq_map[key] != int(key):
                is_valid = False
                break

        if is_valid:
            return num
"""
424. Longest Repeating Character Replacement

You are given a string s and an integer k. You can choose any character of the string and change it to any 
other uppercase English character. You can perform this operation at most k times.

Return the length of the longest substring containing the same letter you can get after performing the above operations.

 

Example 1:

Input: s = "ABAB", k = 2
Output: 4
Explanation: Replace the two 'A's with two 'B's or vice versa.
Example 2:

Input: s = "AABABBA", k = 1
Output: 4
Explanation: Replace the one 'A' in the middle with 'B' and form "AABBBBA".
The substring "BBBB" has the longest repeating letters, which is 4.
There may exists other ways to achieve this answer too.
"""


def characterReplacement(self, s: str, k: int) -> int:
    
    n = len(s)
    char_freq = defaultdict(int)
    left, right = 0, 0
    ans = 0
    max_freq = 0

    while right < n:

        char_freq[s[right]] += 1
        max_freq = max(max_freq, char_freq[s[right]])

        len_window = right - left + 1

        if len_window - max_freq <= k:
            ans = max(ans, len_window)
        else:
            while right - left + 1 - max_freq > k:
                char_freq[ s[left] ] -= 1
                left += 1

        right += 1

    return ans

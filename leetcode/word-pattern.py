"""
Word Pattern | LC - 290
Given a pattern and a string s, find if s follows the same pattern.

Here follow means a full match, such that there is a bijection between a letter in pattern and a non-empty word in s. Specifically:

Each letter in pattern maps to exactly one unique word in s.
Each unique word in s maps to exactly one letter in pattern.
No two letters map to the same word, and no two words map to the same letter.

Example 1:

Input: pattern = "abba", s = "dog cat cat dog"
Output: true

Explanation:
The bijection can be established as:

'a' maps to "dog".
'b' maps to "cat".

Example 2:

Input: pattern = "abba", s = "dog cat cat fish"
Output: false
"""

def wordPattern(self, pattern: str, s: str) -> bool:

    pattern_to_word = {}
    word_to_pattern = {}

    word_list = s.split()

    n = len(word_list)

    if len(pattern) != n:
        return False

    for i in range(n):

        if pattern[i] in pattern_to_word and pattern_to_word[pattern[i]] != word_list[i]:
            return False

        elif pattern[i] not in pattern_to_word:

            if word_list[i] in word_to_pattern and word_to_pattern[ word_list[i] ] != pattern[i]:
                return False

            pattern_to_word[pattern[i]] = word_list[i]
            word_to_pattern[word_list[i]] = pattern[i]

    return True
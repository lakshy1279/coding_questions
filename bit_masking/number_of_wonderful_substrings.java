// A wonderful string is a string where at most one letter appears an odd number of times.

// For example, "ccjjc" and "abab" are wonderful, but "ab" is not.
// Given a string word that consists of the first ten lowercase English letters ('a' through 'j'), return the number of wonderful non-empty substrings in word. If the same substring appears multiple times in word, then count each occurrence separately.

// A substring is a contiguous sequence of characters in a string.


class Solution {
    public long wonderfulSubstrings(String word) {
        long ans = 0;
        HashMap<Integer, Integer> freq = new HashMap<>();
        int mask = 0;
        int n = word.length();
        freq.put(mask, 1);
        for(int i = 0; i < n; i++)
        {
            int bit = word.charAt(i) - 'a';
            mask ^= (1 << bit);
            ans += freq.getOrDefault(mask, 0);
            freq.put(mask, freq.getOrDefault(mask, 0) + 1); // when all are even bits
            for(int odd_c = 0; odd_c < 10; odd_c++)
            {
                ans += freq.getOrDefault((mask ^ (1 << odd_c)), 0); // subtract valid ans to check if any prefix exist for that
            }
        }
        return ans;
    }
}
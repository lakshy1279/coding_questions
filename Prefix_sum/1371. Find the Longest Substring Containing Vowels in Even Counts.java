// Given the string s, return the size of the longest substring containing each vowel an even number of times. That is, 'a', 'e', 'i', 'o', and 'u' must appear an even number of times.

 

// Example 1:

// Input: s = "eleetminicoworoep"
// Output: 13
// Explanation: The longest substring is "leetminicowor" which contains two each of the 


//Solution:

class Solution {
    public int findTheLongestSubstring(String s) {
        int currentMask = 0;
        HashMap<Integer, Integer> prefix = new HashMap<>();
        HashMap<Character, Integer> charMapping = new HashMap<>();
        charMapping.put('a', 0);
        charMapping.put('e', 1);
        charMapping.put('i', 2);
        charMapping.put('o', 3);
        charMapping.put('u', 4);
        int length = 0;
        prefix.put(currentMask, -1);
        for(int i = 0; i < s.length(); i++)
        {
            if(charMapping.containsKey(s.charAt(i)))
            {
                int pos = charMapping.get(s.charAt(i));
                currentMask = currentMask ^ (1 << pos);
                if(prefix.containsKey(currentMask))
                {
                    int index = prefix.get(currentMask);
                    length = Math.max(length, i - index);
                }
                else
                 prefix.put(currentMask, i);
            }
            else
            {
                int index = prefix.get(currentMask);
                length = Math.max(length, i - index);
            }
        }
        return length;
    }
}
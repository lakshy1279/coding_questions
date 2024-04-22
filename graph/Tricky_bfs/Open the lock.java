// You have a lock in front of you with 4 circular wheels. Each wheel has 10 slots: '0', '1', '2', '3', '4', '5', '6', '7', '8', '9'. The wheels can rotate freely and wrap around: for example we can turn '9' to be '0', or '0' to be '9'. Each move consists of turning one wheel one slot.

// The lock initially starts at '0000', a string representing the state of the 4 wheels.

// You are given a list of deadends dead ends, meaning if the lock displays any of these codes, the wheels of the lock will stop turning and you will be unable to open it.

// Given a target representing the value of the wheels that will unlock the lock, return the minimum total number of turns required to open the lock, or -1 if it is impossible.

// Input: deadends = ["0201","0101","0102","1212","2002"], target = "0202"
// Output: 6
// Explanation: 
// A sequence of valid moves would be "0000" -> "1000" -> "1100" -> "1200" -> "1201" -> "1202" -> "0202".
// Note that a sequence like "0000" -> "0001" -> "0002" -> "0102" -> "0202" would be invalid,
// because the wheels of the lock become stuck after the display becomes the dead end "0102".
// Example 2:

// Input: deadends = ["8888"], target = "0009"
// Output: 1
// Explanation: We can turn the last wheel in reverse to move from "0000" -> "0009".

class Solution {
    Set<String> visited;
     Map<Character, Character> nextSlot = Map.of(
            '0', '1', 
            '1', '2', 
            '2', '3', 
            '3', '4', 
            '4', '5', 
            '5', '6', 
            '6', '7', 
            '7', '8', 
            '8', '9', 
            '9', '0'
        );
        // Map the previous slot digit for each current slot digit.
        Map<Character, Character> prevSlot = Map.of(
            '0', '9', 
            '1', '0', 
            '2', '1', 
            '3', '2', 
            '4', '3', 
            '5', '4', 
            '6', '5', 
            '7', '6', 
            '8', '7', 
            '9', '8'
        );
    public int openLock(String[] deadends, String target) {
        visited = new HashSet<>();
        for (String dead : deadends) {
            visited.add(dead);
        }
        if(visited.contains("0000"))
            return -1;
        Queue<String> queue = new LinkedList<>();
        queue.add("0000");
      
        int count = 0;
        visited.add("0000");
        while (!queue.isEmpty()) {
            int size = queue.size();
            while (size > 0) {
                String currCombination = queue.poll();
                if(currCombination.equals(target))
                {
                    return count;
                }
                for (int i = 0; i < 4; i++) {
                  StringBuilder newCombination = new StringBuilder(currCombination);
                  newCombination.setCharAt(i, nextSlot.get(newCombination.charAt(i)));
                  if(!visited.contains(newCombination.toString()))
                  {
                    queue.add(newCombination.toString());
                    visited.add(newCombination.toString());
                  }
                   newCombination = new StringBuilder(currCombination);
                   newCombination.setCharAt(i, prevSlot.get(newCombination.charAt(i)));
                    if(!visited.contains(newCombination.toString()))
                    {
                        queue.add(newCombination.toString());
                        visited.add(newCombination.toString());
                    }
                }
                size--;
            }
            count++;
        }
        return -1;
    }
}
// You are given an m x n grid grid where:

// '.' is an empty cell.
// '#' is a wall.
// '@' is the starting point.
// Lowercase letters represent keys.
// Uppercase letters represent locks.
// You start at the starting point and one move consists of walking one space in one of the four cardinal directions. You cannot walk outside the grid, or walk into a wall.

// If you walk over a key, you can pick it up and you cannot walk over a lock unless you have its corresponding key.

// For some 1 <= k <= 6, there is exactly one lowercase and one uppercase letter of the first k letters of the English alphabet in the grid. This means that there is exactly one key for each lock, and one lock for each key; and also that the letters used to represent the keys and locks were chosen in the same order as the English alphabet.

// Return the lowest number of moves to acquire all keys. If it is impossible, return -1.


// See how beuatifuly we use bitmasking and in this bfs we can backtrack on the basic of stage of keys.
// want to find shortest so bfs should apply and after that figure out how bfs should apply.


class Solution {
    public int shortestPathAllKeys(String[] grid) {
        int m = grid.length, n = grid[0].length();
        int [][]moves = new int[][] {{0,1}, {1,0},{-1,0},{0,-1}};
        Queue<int[]>pq = new LinkedList<>();
        Map<Integer, Set<Pair<Integer, Integer>>> seen = new HashMap<>();
        int startR = -1, startC = -1;
        int allKey = 0;
        Set<Character>locks = new HashSet<>();
        Set<Character>keys = new HashSet<>();
        for(int i = 0; i < m; i++)
        {
            for(int j = 0; j < n; j++)
            {
                if(grid[i].charAt(j) == '@')
                {
                    startR = i;
                    startC = j;
                }
                else if(grid[i].charAt(j) >= 'a' && grid[i].charAt(j) <= 'f')
                {
                    keys.add(grid[i].charAt(j));
                    allKey += ( 1 << (grid[i].charAt(j) - 'a') );
                }
            }
        }
        pq.add(new int[]{startR, startC, 0, 0});
        seen.put(0, new HashSet<>());
        seen.get(0).add(new Pair<>(startR,startC));
        while(!pq.isEmpty())
        {
            int []top = pq.poll();
            int currR = top[0], currC = top[1], key = top[2], steps = top[3];
            if(key == allKey)
            return steps;
            for(int []move : moves)
            {
                int movR = currR + move[0];
                int movC = currC + move[1];
                if(movR >= 0 && movC >= 0 && movR < m && movC < n && grid[movR].charAt(movC) != '#')
                {
                  char cell = grid[movR].charAt(movC);
                  int newKey = key;
                   if(cell >= 'a' && cell <= 'f')
                    {
                        int index = cell - 'a';
                        newKey =  ( key | (1 << index));
                    }
                    else if((cell >= 'A' && cell <= 'F') && ((key & (1 << (cell - 'A'))) == 0))
                    {
                       continue;
                    }
                    if(seen.get(newKey) == null || !seen.get(newKey).contains(new Pair<>(movR, movC)))
                    {
                        seen.putIfAbsent(newKey, new HashSet<>());
                        seen.get(newKey).add(new Pair<>(movR,movC));
                        pq.offer(new int[]{movR, movC, newKey, steps + 1});
                    }
                }
            }
        }
        return -1;
    }
}
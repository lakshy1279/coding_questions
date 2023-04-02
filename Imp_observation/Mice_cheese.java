// There are two mice and n different types of cheese, each type of cheese should be eaten by exactly one mouse.

// A point of the cheese with index i (0-indexed) is:

// reward1[i] if the first mouse eats it.
// reward2[i] if the second mouse eats it.
// You are given a positive integer array reward1, a positive integer array reward2, and a non-negative integer k.

// Return the maximum points the mice can achieve if the first mouse eats exactly k types of cheese.

// In this we need to pick k from the reward1 and remaining from reward2;
// the k we pick from reward1 will be those index which have max value in reward1 and min in reward2
// we achieve this taking subtraction from reward2 - reward1 and sorting this.
// by sorting at the starting we have those element which have high reward1 value and low reward2 value.

class Solution {
    public class Pair
    {
        int first;
        int second;
        Pair(int a, int b)
        {
            this.first = a;
            this.second = b;
        }
    }
    public int miceAndCheese(int[] reward1, int[] reward2, int k) {
        int n = reward1.length;
        Pair diff[] = new Pair[n];
        for(int i = 0; i < n; i++)
        {
            diff[i] = new Pair(reward2[i] - reward1[i], i);
        }
        Arrays.sort(diff, new Comparator<Pair>() {
            @Override
            public int compare(Pair p1, Pair p2) {
                return p1.first - p2.first;
            }
        });
        int ans = 0;
        for(int i = 0; i < k; i++)
        {
            ans += reward1[diff[i].second];
        }
        for(int i = k ; i < n; i++)
        {
            ans += reward2[diff[i].second];
        }
        return ans;
    }
}
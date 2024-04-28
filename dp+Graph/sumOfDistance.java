// There is an undirected connected tree with n nodes labeled from 0 to n - 1 and n - 1 edges.

// You are given the integer n and the array edges where edges[i] = [ai, bi] indicates that there is an edge between nodes ai and bi in the tree.

// Return an array answer of length n where answer[i] is the sum of the distances between the ith node in the tree and all other nodes.

 

// Example 1:


// Input: n = 6, edges = [[0,1],[0,2],[2,3],[2,4],[2,5]]
// Output: [8,12,6,10,10,10]
// Explanation: The tree is shown above.
// We can see that dist(0,1) + dist(0,2) + dist(0,3) + dist(0,4) + dist(0,5)
// equals 1 + 1 + 2 + 2 + 2 = 8.
// Hence, answer[0] = 8, and so on.

// Now, to use the insight explained previously: if we have a node parent and it's child child, then these are neighboring nodes, and so ans[child] = ans[parent] - count[child] + (N - count[child]). This is because there are count[child] nodes that are 1 easier to get to from child than parent, and N-count[child] nodes that are 1 harder to get to from child than parent

class Solution {
    int []ans, count;
    List<Set<Integer>> graph;
    int N;
    public int[] sumOfDistancesInTree(int n, int[][] edges) {
       this.N = n;
       graph = new ArrayList<>();
       for(int i = 0; i < n; i++)
       {
         graph.add(new HashSet<Integer>());
       }
       ans = new int[n];
       count = new int[n];
       Arrays.fill(count, 1);
       for(int []edge: edges)
       {
          graph.get(edge[0]).add(edge[1]);
          graph.get(edge[1]).add(edge[0]);
       }
       postOrder(0, -1);
       dfs(0, -1);
       return ans;
    }
    void postOrder(int node, int parent)
    {
        for(int child : graph.get(node))
        {
            if(child != parent)
            {
                postOrder(child, node);
                count[node] += count[child];
                ans[node] += ans[child] + count[child];
            }
        }
    }
    void dfs(int node, int parent)
    {
        for(int child : graph.get(node))
        {
           if(child != parent)
           {
            ans[child] = ans[node] - count[child] + (N - count[child]);
            dfs(child, node);
           }
        }
    }
}
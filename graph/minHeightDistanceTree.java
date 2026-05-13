// A tree is an undirected graph in which any two vertices are connected by exactly one path. In other words, any connected graph without simple cycles is a tree.

// Given a tree of n nodes labelled from 0 to n - 1, and an array of n - 1 edges where edges[i] = [ai, bi] indicates that there is an undirected edge between the two nodes ai and bi in the tree, you can choose any node of the tree as the root. When you select a node x as the root, the result tree has height h. Among all possible rooted trees, those with minimum height (i.e. min(h))  are called minimum height trees (MHTs).

// Return a list of all MHTs' root labels. You can return the answer in any order.

// The height of a rooted tree is the number of edges on the longest downward path between the root and a leaf.


// Input: n = 4, edges = [[1,0],[1,2],[1,3]]
// Output: [1]
// Explanation: As shown, the height of the tree is 1 when the root is the node with label 1 which is the only MHT.

// concept is tree can always have two centroids so at max there is 2 ans only
// since distance from leaves is always largest so start removeing from leave nodes and at last one or two nodes remains which is our ans.


class Solution {
    public List<Integer> findMinHeightTrees(int n, int[][] edges) {
        if(n == 1)
        return Collections.singletonList(0);
        List<Set<Integer>> adj = new ArrayList<>();
        for(int i = 0; i < n; i++) adj.add(new HashSet<>());
        for(int []edge : edges){
            adj.get(edge[0]).add(edge[1]);
            adj.get(edge[1]).add(edge[0]);
        }

        List<Integer> leaves = new ArrayList<>();
        for(int i = 0; i < n; i++){
            if(adj.get(i).size() == 1)
             leaves.add(i);
        }

        while(n > 2){
            n -= leaves.size();
            List<Integer> newLeaves = new ArrayList<>();
            for(int i : leaves) {
                int node = adj.get(i).iterator().next();
                adj.get(node).remove(i);
                if(adj.get(node).size() == 1) newLeaves.add(node);
            }
            leaves = newLeaves;
        }
        return leaves;
    }
}


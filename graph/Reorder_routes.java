// There are n cities numbered from 0 to n - 1 and n - 1 roads such that there is only one way to travel between two different cities (this network form a tree). Last year, The ministry of transport decided to orient the roads in one direction because they are too narrow.

// Roads are represented by connections where connections[i] = [ai, bi] represents a road from city ai to city bi.

// This year, there will be a big event in the capital (city 0), and many people want to travel to this city.

// Your task consists of reorienting some roads such that each city can visit the city 0. Return the minimum number of edges changed.

// It's guaranteed that each city can reach city 0 after reorder.


// IMP POINT TO NOTICE:
// here we need to find the edge which in forward direction when we start traverse from 0.
// but if we case like 1<-2->0 we cannot travel from 0 but we need to revert one edge.
// so we make this graph as undirected by adding another edge like u to -v and if we encounter postive edge then we increase the answer.
// as there is no cycle so we always move forward.

class Solution {
    public int dfs(ArrayList<ArrayList<Integer>> graph, int si, int visited[])
    {
        int count = 0;
        visited[si] = 1;
        for(int i = 0; i < graph.get(si).size(); i++)
        {
            int v = graph.get(si).get(i);
            if(visited[Math.abs(v)] == 0)
            {
                if(v > 0)
                    count++;
              count += dfs(graph, Math.abs(v), visited);
            }
        }
        return count;
    }
    public int minReorder(int n, int[][] connections) {
        ArrayList<ArrayList<Integer>> graph = new ArrayList<ArrayList<Integer>>();
        for(int i = 0; i < n; i++)
        {
            graph.add(new ArrayList<Integer>());
        }
        for(int i = 0; i < connections.length; i++)
        {
            int u = connections[i][0];
            int v = connections[i][1];
            graph.get(u).add(v);
            graph.get(v).add(-u);
        }
        int []visited = new int[n];
        int count = 0;
        count += dfs(graph, 0, visited);
        return count;
    }
}
class Solution {
public:
    bool bipartitionHelper(vector<int>adj[], int src, int color, vector<int> &visited)
    {
     // we are not checking visited[src] == color directly because their might be the case when we visit a visited node that has different color than the current node
     // and in that case we again visit the visited node and chnage it's original color;
        if( visited[src] != -1)
            return visited[src] == color;
        visited[src] = color;
        bool ans = true;
        color = !color;
        for( auto &it : adj[src] )
        {
           
            ans = ans && bipartitionHelper(adj, it, color, visited);
        }
        return ans;
    }
    bool possibleBipartition(int n, vector<vector<int>>& dislikes) {
        vector<int>adj[n + 1];
        for( auto &it : dislikes )
        {
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }
        vector<int>color(n + 1, -1);
      for( int i = 1; i <= n ; i++)
      {
          if(color[i] == -1 && !bipartitionHelper(adj, i, 0, color))
          {
              //cout<<i<<" "<< color[i];
           return false; 
          }
      }
      return true;
    }
};

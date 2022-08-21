class Solution {
public:
    void dfs(vector<int>adj[], vector<bool> &visited, int src)
    {
        visited[src] = true;
        for(int i = 0 ; i < adj[src].size() ; i++)
        {
            if(!visited[adj[src][i]])
            {
                dfs( adj, visited, adj[src][i]  );
            }
        }
    }
    
    int makeConnected(int n, vector<vector<int>>& conn) {
        //if graph has more no of edges than vertices - 1 then graph has full connected
        if(conn.size()<n-1)
            return -1;
        vector<int>adj[n];
        for( int i = 0 ; i < conn.size() ; i++ )
        {
            adj[conn[i][0]].push_back(conn[i][1]);
            adj[conn[i][1]].push_back(conn[i][0]);
        }
        vector<bool>visited(n,false);
        int count = 0;
        // the no of disconnected component is the ans of no of edges
        for(int i = 0 ; i < n ; i++)
        {
            if(!(visited[i]))
            {
                dfs(adj,visited,i);
                count++;
            }
            
        }
        return count - 1;
    }
};

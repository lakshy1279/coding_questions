// in this we have different color edges like 0-1 with red and same 0-1 with blue so in this case we have to take the minimum of the two.
class Solution {
public:
    vector<int> shortestAlternatingPaths(int n, vector<vector<int>>& redEdges, vector<vector<int>>& blueEdges) {
        vector<vector<pair<int,int>>> graph(n);
        for(auto edge: redEdges)
            graph[edge[0]].emplace_back(edge[1],0); 
        for(auto edge: blueEdges)
            graph[edge[0]].emplace_back(edge[1],1); 
        queue<vector<int>>pq;
        pq.emplace(vector<int>{0,0,-1});
        vector<int>dist(n,-1);
        while(!pq.empty())
        {
            auto front = pq.front();
            pq.pop();
            dist[front[0]] = dist[front[0]] != -1 ? dist[front[0]] : front[1]; // take the min
            for( auto &adj : graph[front[0]] ) // with auto & we point to the same location not create the copy
            {
                if( adj.second != front[2] && adj.first != -1) // mark visited with -1;
                {
                     pq.emplace(vector<int>{adj.first, front[1] + 1, adj.second});
                     adj.first = -1 ; // point to the reference of the node and made this -1
                }
            }
        }
        return dist;
    }
 };
//Ex:
//3
//[[0,1],[0,2]]
//[[1,0]]

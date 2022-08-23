class Solution {
public:
    int shortestPathLength(vector<vector<int>>& graph) {
        int n = graph.size();
        // to track the visited node
        set<pair<int,int>>vis;
        queue< pair < int, pair < int, int > > >pq;
        for( int i = 0; i < n ;i++)
        {
          int maskValue = (1<<i);
          pq.push({i,{maskValue,0}}); // to keep the thing of visited state
          vis.insert({i,maskValue});
        }
        int all = (1 << n) - 1;
        while(!pq.empty())
        {
            auto [node, Pair] = pq.front();
            int dist = Pair.second;
            pq.pop();
            if( Pair.first == all )
                return dist;
            //cout<<node<<" "<<Pair.first<<endl;
            for( auto adj : graph[node])
            {
                int maskValue = Pair.first | (1<<adj);
                if(vis.find({ adj, maskValue}) == vis.end())
                {
                    //cout<<adj<<" "<<maskValue<<" ";
                    pq.push({adj,{maskValue,dist+1}});
                    vis.insert({adj, maskValue});
                }
            }
            //cout<<endl;
        }
        return -1;
    }
};

//store the path at every index
//it is the implementation of dijkstra algorith with dp.
// we use set or priority_queue inspect of queue to avoid repeation.
//at every node store what are the no of paths that reached with minimum weight.
class Solution {
public:
    int MOD=1000000007;
    int dijkstra(int n,vector<pair<int,int>>graph[])
    {
        set<pair<long long,long long>>st;
        st.insert({0,0});
        vector<long long>ways(n,0);
        vector<long long>dist(n,1000000000000000);
        ways[0]=1;
        dist[0]=0;
        while(!st.empty())
        {
            pair<int,int>pq=*(st.begin());
            st.erase(st.begin());
            long u=pq.second;
            for(auto it:graph[pq.second])
            {
                long long node=it.first;
                long long weight=it.second;
                if(dist[u]+weight<dist[node])
                {
                    st.erase({dist[node],node});
                    dist[node]=dist[u]+weight;
                    ways[node]=ways[u];
                    st.insert({dist[node],node});
                }
                else if(dist[u]+weight==dist[node])
                    ways[node]=(ways[node]+ways[u])%MOD;
            }
        }
        return ways[n-1]%MOD;
    }
    int countPaths(int n, vector<vector<int>>& roads) {
        vector<pair<int,int>>graph[n];
        for(auto &vec:roads)
        {
            graph[vec[0]].push_back({vec[1],vec[2]});
            graph[vec[1]].push_back({vec[0],vec[2]});
        }
        return dijkstra(n,graph);
    }
};

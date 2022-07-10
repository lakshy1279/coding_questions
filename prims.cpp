//minimum spanning tree is the tree with n-1 edges connect all the vertices.
//but a graph that is not connected will not contain a spanning tree.
//in this we take a set for getting minimum weight edge and procees.
//st.erase()--> The function returns the number of elements erased, which in set containers is 1 if an element with a value of x existed (and thus was subsequently erased), and zero otherwise.
//this algorithm does not work for directed graph because we not able to traverse the full tree from any node with minimum no of edges.

int spanningTree(int V, vector<vector<int>> adj[])
    {
        set<vector<int>>st;
        vector<bool>visited(V,false);
        vector<int>min_w(V,INT_MAX);
        st.insert({0,0});
        min_w[0]=0;
        int ans=0;
        for(int i=0;i<V;i++)
        {
            if(st.empty())
             return -1;
            vector<int>curr=*(st.begin());
            st.erase(st.begin());
            ans+=curr[0];
            // cout<<ans<<endl;
            visited[curr[1]]=true;
            for(auto &e:adj[curr[1]])
            {
                int nb=e[0],w=e[1];
                if(visited[nb])
                continue;
                // cout<<nb<<" "<<e[1]<<" ";
                if(min_w[nb]>w)
                {
                    //removing the pervious occurence of this node with higher weight if exist.
                    st.erase({min_w[nb],nb});
                    min_w[nb]=w;
                    st.insert({min_w[nb],nb});
                }
            }
        }
        return ans;

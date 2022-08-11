// binary lifting concept question
#define MAX 100001
//Lets define an adjacency matrix
vector<int> adj[MAX];
//Map to store the weights of the edges
map<vector<int>, int> umap;
void dfs(int node, int parent, vector<vector<int>> &dp, vector<int> &lvl, vector<vector<int>> &mx){
    dp[node][0] = parent;
    for(auto x : adj[node])
    {
        if(x != parent)
        {
            lvl[x] = lvl[node] + 1;
            dfs(x, node, dp, lvl, mx);
            mx[x][0] = umap[{node, x}];
        }
    }
}
vector<int> Solution::solve(vector<vector<int> > &A, vector<vector<int> > &B) {
    for(int i=0; i<MAX; i++)
        adj[i].clear();
    umap.clear();
    vector<int> res;
    //Number of edges
    int edges = A.size();
    for(int i=0; i<edges; i++)
    {
        int u = A[i][0]-1;
        int v = A[i][1]-1;
        adj[u].push_back(v);
        adj[v].push_back(u);
        umap[{u, v}] = A[i][2];
        umap[{v, u}] = A[i][2];
    }
    //The nodes are defined to [0, n)
    //The number of nodes are equal to edges + 1
    int n = edges+1;
    //Max generations we can have
    int maxG = (int)log2(n);
    //Define the DP array and the level array
    vector<vector<int>> dp(n, vector<int>(maxG+1, -1));
    vector<int> lvl(n, -1);
    //Also we need a array to store the max weight edge
    //till some 2^generation above a node.
    vector<vector<int>> mx(n, vector<int>(maxG+1, -1));
    lvl[0] = 0;
    //Intialise the immediate parents and their weights
    dfs(0, -1, dp, lvl, mx);
    
    //Define the higher generations using binary lifting technique
    for(int j=1; j<=maxG; j++)
    {
        for(int i=0; i<n; i++)
        {
            //We check if the ancestor of i at j level exist
            if(dp[i][j-1] != -1)
            {
                int par = dp[i][j-1];
                dp[i][j] = dp[par][j-1];
                int parWgt = mx[i][j-1];
                //We have the 2^jth parent weight
                //We choose the max weight edge in the entire ancestry till 2^j 
                mx[i][j] = max(parWgt, mx[par][j-1]);
            }
        }
    }
    
    //Answer the call!
    int q = B.size();    //Number of queries
    for(int i=0; i<q; i++)
    {
        int ans = INT_MIN;
        //First node
        int a = B[i][0]-1;
        //Second node
        int b = B[i][1]-1;
        //Lets find the LCA
        if(lvl[a] < lvl[b])
            swap(a,b);
        int diff = lvl[a] - lvl[b]; //a is at more depth
        //Move up till b and a are at the same level
        //The jump keeps on getting bigger
        while(diff)
        {
            //Max jump allowed
            int j = log2(diff);
            ans = max(ans, mx[a][j]);
            a = dp[a][j];
            //Update diff
            diff = diff - (1<<j);
        }
        //It is possible that a and b coincide now
        if(a==b)
        {
            res.push_back(ans);
            continue;
        }
        //Now a and b are at the same level
        for(int j = maxG; j>=0; j--)
        {
            //Check if maxG level ancestor exit and that this level ancestor is not same
            //for the nodes because that would mean overshooting the LCA
            if(dp[a][j] != -1 && (dp[a][j] != dp[b][j]))
            {
                ans = max(ans, max(mx[a][j], mx[b][j]));
                a = dp[a][j];
                b = dp[b][j];
            }
        }
        //a and b are just below their LCA at this stage
        res.push_back(max(ans, max(mx[a][0], mx[b][0])));
    }
    return res;
}

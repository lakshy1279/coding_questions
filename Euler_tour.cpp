//use when we want to remove the particular subtree


vector<int>arr[100005];
vector<int>eulerTour;
vector<bool>vis(100005,false);
vector<int>level(100005,0);//store the level of each node
map<int,int> start;
map<int,int> ended;
class Solution
{
void dfs(int src,int lev=0)
{
    vis[src]=true;
    level[src]=lev;
    //entry in the Euler tour
    eulerTour.push_back(src);
    for(auto &it:arr[src])
    {
        if(!vis[it])
        {
            dfs(it,lev+1);
        }
    }
  //exit of the Euler Tour
    eulerTour.push_back(src);
}
  public:
vector<int> solve(int N, int Q, vector<vector<int> > &Edge,vector<vector<int> > &query) {
        for(int i=0;i<Edge.size();i++)
        {
            arr[Edge[i][0]].push_back(Edge[i][1]);
            arr[Edge[i][1]].push_back(Edge[i][0]);
        }
        dfs(0);
        int k=0;
        for(auto &it:eulerTour)
        {
            if(start.find(it)==start.end())
            {
                start[it]=k;
            }
            else
            ended[it]=k;
            k++;
        }
        int size=eulerTour.size();
        // for(int i=0;i<size;i++)
        // cout<<eulerTour[i]<<" ";
        // cout<<endl;
        //store the maximum level in euler tour from front and end
        vector<int> pref(size+1,0), suf(size + 1,0);
        for (int i = 1; i < size; i++) {
            pref[i] = max(pref[i - 1], level[eulerTour[i]]);
        }
        for (int i = size-1; i >= 0; i--) {
            suf[i] = max(suf[i + 1], level[eulerTour[i]]);
        }
        vector<int>answer(Q);
        for(int i=0;i<query.size();i++)
        {
             int node=query[i][0];
             if (level[query[i][1]] > level[query[i][0]]) node = query[i][1];
             cout<<node<<" ";
             cout<<max(pref[start[node] - 1], suf[ended[node] + 1])<<endl;
             answer[i] = max(pref[start[node] - 1], suf[ended[node] + 1]);
        }
        // for(int i=0;i<answer.size();i++)
        // cout<<answer[i]<<" ";
        // cout<<endl;
        return answer;
    }
};

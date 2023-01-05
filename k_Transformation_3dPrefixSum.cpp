//https://practice.geeksforgeeks.org/contest/mega-job-a-thon-hiring-challenge-for-experienced-candidates/problems/#
class Solution {
  public:
    int find(vector<vector<int> > &pref, int i, int j){
        if(i < 0 || j < 0)
            return 0;
        return pref[i][j];
    }

    void fill2DPrefix(vector<vector<int> > &pref, vector<vector<int> > &grid, int x, int n, int m){
        pref[0][0] = (grid[0][0] == x ? 1 : 0);
        for(int i = 1; i < n; i++)
            pref[i][0] = pref[i - 1][0] + (grid[i][0] == x ? 1 : 0);
        for(int j = 1; j < m; j++)
            pref[0][j] = pref[0][j - 1] + (grid[0][j] == x ? 1 : 0);

        for(int i = 1; i < n; i++){
            for(int j = 1; j < m; j++){
                pref[i][j] = pref[i - 1][j] + pref[i][j - 1] - pref[i - 1][j - 1] + (grid[i][j] == x ? 1 : 0);
            }
        }
    }


    vector<int> k_Transformation(int n, int m, int k, vector<vector<int> > grid, int q, vector<vector<int> > queries) {
       // vector to store the prefix matrix for every k value because our ans require these only. 
        vector<vector<int> > pref[k];
        for(int x = 0; x < k; x++) {
            // create the 2d-matrix for every k value.
            // it store count at every index of value k occur till that index.
            pref[x].assign(n, vector<int> (m, 0));
            fill2DPrefix(pref[x], grid, x, n, m);
        }
        
        vector<int> ans(q);
        for(int i = 0; i < q; i++){
            int time = queries[i][0];
            int val = queries[i][1];
            int lx = queries[i][2];
            int ly = queries[i][3];
            int rx = queries[i][4];
            int ry = queries[i][5];
            // value x that we need to get 
            int x = (val - time % k + k) % k;
            
            int temp = find(pref[x], rx, ry) - find(pref[x], rx, ly - 1) - find(pref[x], lx - 1, ry) + find(pref[x], lx - 1, ly - 1);
            ans[i] = temp;
        }
        return ans;
    }
};

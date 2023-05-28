// Given a 1-indexed m x n integer matrix mat, you can select any cell in the matrix as your starting cell.

// From the starting cell, you can move to any other cell in the same row or column, but only if the value of the destination cell is strictly greater than the value of the current cell. You can repeat this process as many times as possible, moving from cell to cell until you can no longer make any moves.

// Your task is to find the maximum number of cells that you can visit in the matrix by starting from some cell.

// Return an integer denoting the maximum number of cells that can be visited.

// the observation here is to to see that we sort the matrix element and travel from greatet to lowest or from lowest to greatest
// becuase it will only give us the longest path and how beutifuly we use the row and col to keep track.

class Solution {
public:
    int maxIncreasingCells(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();
        map<int,vector<pair<int,int>>> temp;
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < m; j++)
            {
               temp[mat[i][j]].push_back({i,j});
            }
        }
        vector<vector<int>>dp(n, vector<int>(m, 0));
        vector<int>col(m, 0);
        vector<int>row(n, 0);
        for(auto &[val, po] : temp)
        {
           for(auto [x,y] : po)
           {
               dp[x][y] = max(dp[x][y], max(col[y], row[x]) + 1);
           }
           for(auto [x,y] : po)
           {
               col[y] = max(col[y], dp[x][y]);
               row[x] = max(row[x], dp[x][y]);
           }
        }
        int ans = max(*max_element(row.begin(), row.end()), *max_element(col.begin(), col.end()));
        return ans;
    }
};
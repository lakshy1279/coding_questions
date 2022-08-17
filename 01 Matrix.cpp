class Solution {
public:
    vector<vector<int>>dirs={{1,0},{0,1},{0,-1},{-1,0}};
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
         //1st Method
         queue<pair < int, int > >pq;
        int m=mat.size();
        int n=mat[0].size();
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(mat[i][j]==0)
                {
                    pq.push({i,j});
                }
                else
                    mat[i][j]=-1; // to make use of same matrix for visited sometime we mark the cell which is going to visit and we apply condition on them.
            }
        }
        
        while(!pq.empty())
        {
            int size = pq.size();
            while(size--)
            {
                auto front = pq.front();
                pq.pop();
                int x = front.first;
                int y = front.second;
                for(int i=0;i<4;i++)
                {
                    int newx = x + dirs[i][0];
                    int newy = y + dirs[i][1];
                    if(newx>=0&&newy>=0&&newx<m&&newy<n&&(mat[newx][newy]==-1)) // here we check mat[i][j] == -1 as we mark the cell that going to visit.
                    {
                        pq.push({newx,newy});
                        mat[newx][newy] = mat[x][y] + 1;
                    }
                }
            }
        }
        return mat;
      
    // 2nd Method solution
    // To work this with dp we have to first visit it from the top and then from bottom or vice versa. we did this because we do not know whether 0 in 
    // in middle or not or we need to consider from both side.
      int INF = m + n;
        for( int i=0 ; i < m ; i++ )
        {
            for( int j = 0 ; j < n ; j++)
            {
                if(mat[i][j]==0)
                    continue;
                int left = INF,top=INF;
                if(i-1>=0)
                    top = mat[i-1][j];
                if(j-1>=0)
                    left = mat[i][j-1];
                mat[i][j] = min( top,left ) + 1;
            }
        }
        for( int i = m-1 ; i>=0 ; i-- )
        {
            for( int j = n-1 ; j>=0 ; j--)
            {
                if (mat[i][j] == 0) continue;
                int bottom = INF, right = INF;
                if(i+1<m)
                    bottom = mat[i+1][j];
                if(j+1<n)
                    right = mat[i][j+1];
                mat[i][j] = min(mat[i][j],min(bottom,right) + 1 );
            }
        }
        return mat;
    }
};

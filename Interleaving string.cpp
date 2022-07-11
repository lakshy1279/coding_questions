class Solution {
public:
    
    // bool helper(string s1, string s2, string s3,int i,int j,int k,vector<vector<int>> &dp)
    // {
    //     if(k==s3.size())
    //         return true;
    //     if(dp[i][j]!=-1)
    //         return dp[i][j];
    //     bool ans=false;
    //     if( i<s1.size() && s1[i] == s3[k] )
    //         ans = ans || helper(s1,s2,s3,i+1,j,k+1,dp);
    //     if( j<s2.size() && s2[j] == s3[k] )
    //         ans = ans || helper(s1,s2,s3,i,j+1,k+1,dp);
    //     return dp[i][j] = ans;
    // }
    bool isInterleave(string s1, string s2, string s3) {
        int size1=s1.size(),size2=s2.size(),size3=s3.size();
        vector<vector<bool>>dp(size1+1,vector<bool>(size2+1,false)) ;
        if(size1+size2!=size3)
            return false;
        // return helper(s1,s2,s3,0,0,0,dp);
//         vector<vector<bool>>(size1+1,vector<bool>(size2+1,false));
//         for(int i=0;i<size1;i++)
//         {
//             for(int j=0;j<size2;j++)
//             {
                
//             }
//         }
        for(int i=0;i<=size1;i++)
        {
            for(int j=0;j<=size2;j++)
            {
               if( i==0&&j==0 )
                   dp[i][j]=true;
               else if(i==0)
               {
                   if( s2[j-1]==s3[i+j-1] )
                   dp[i][j]=dp[i][j-1];
               }
               else if( j==0 )
               {
                   if( s1[i-1]==s3[i+j-1] )
                   dp[i][j]=dp[i-1][j];
               }
               else
               {
                   if(s2[j-1]==s3[i+j-1])
                    dp[i][j]=dp[i][j-1];
                   if(s1[i-1]==s3[i+j-1])
                     dp[i][j]=dp[i][j]||dp[i-1][j];
               }
            }
        }
        return dp[size1][size2];
    }
};

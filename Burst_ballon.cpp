class Solution {
public:
    // in this we start from the end and we assume that the element we pick is the last ballon that need to burst in the range i to j and calling recursion 
    // on sub cases
    // we assume that the element we pick is the last element because if we assume it as the first element then how we maintain the index of the prev and the next element.
    // recusion follow top-down approach and tabulation follow bottom up approach that's why we start i from n and j from 1
    // int helper(vector<int>& nums,int i,int j,vector<vector<int>> &dp)
    // {
    //     if(i>j)
    //         return 0;
    //     int max_coin=INT_MIN;
    //     if(dp[i][j]!=-1)
    //         return dp[i][j];
    //     for(int ind=i;ind<=j;ind++)
    //     {
    //         int cost=nums[ind]*nums[i-1]*nums[j+1]+helper(nums,i,ind-1,dp)+helper(nums,ind+1,j,dp);
    //         max_coin=max(max_coin,cost);
    //     }
    //     return dp[i][j]=max_coin;
    // }
    int maxCoins(vector<int>& nums) {
        int n=nums.size();
        nums.push_back(1);
        nums.insert(nums.begin(),1);
        vector<vector<int>>dp(n+2,vector<int>(n+2,0));
        for(int i=n;i>=1;i--)
        {
            for(int j=1;j<=n;j++)
            {
                if(i>j)
                    continue;
                int maxi=INT_MIN;
                for(int ind=i;ind<=j;ind++)
                {
                    // cout<<i<<" "<<j<<" "<<ind<<endl;
                    // cout<<nums[ind]<<" "<<nums[i-1]<<" "<<nums[j+1]<<endl;
                    int cost=nums[ind]*nums[i-1]*nums[j+1]+dp[i][ind-1]+dp[ind+1][j];
                    maxi=max(maxi,cost);
                }
                dp[i][j]=maxi;
            }
        }
        return dp[1][n];
    }
};

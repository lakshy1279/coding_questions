// recursive solution with memoriztion

class Solution {
public:
    int ans;
    int helper(int i, int j, vector<int>& nums1, vector<int>& nums2, vector<vector<int>> &dp)
    {
        if( i >= nums1.size() || j >= nums2.size() )
        {
            return 0;
        }
        if(dp[i][j] != -1)
            return dp[i][j];
         // only to traverse the all pair of i and j
         helper(i + 1, j, nums1, nums2, dp);
         helper(i, j + 1, nums1, nums2, dp);
         // this contribute to the ans
         int common = nums1[i] == nums2[j] ? 1 + helper(i + 1, j + 1, nums1, nums2, dp) : 0;
         dp[i][j] = common;
         ans = max(ans,dp[i][j]);
        return dp[i][j];
    }
    int findLength(vector<int>& nums1, vector<int>& nums2) {
         int n = nums1.size();
         int m = nums2.size();
         ans = 0;
        vector<vector<int>>dp(nums1.size(),vector<int>(nums2.size(),-1));
        helper(0,0,nums1,nums2,dp);
        return ans;
    }
};

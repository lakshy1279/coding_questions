// You are given n balloons, indexed from 0 to n - 1. Each balloon is painted with a number on it represented by an array nums. You are asked to burst all the balloons.

// If you burst the ith balloon, you will get nums[i - 1] * nums[i] * nums[i + 1] coins. If i - 1 or i + 1 goes out of bounds of the array, then treat it as if there is a balloon with a 1 painted on it.

// Return the maximum coins you can collect by bursting the balloons wisely.

class Solution {
public:
    int helper(vector<int>& nums, int start, int end, vector<vector<int>> &dp)
    {
        if(start > end)
        return 0;
        int ans = 0;
        if(dp[start][end] != -1)
        return dp[start][end];
        for(int i = start; i <= end; i++)
        {
           int temp = nums[i]*nums[start - 1]*nums[end + 1] + helper(nums, start, i - 1, dp) + helper(nums, i + 1, end, dp);
           ans = max(ans, temp);
        }
        return dp[start][end] = ans;
    }
    int maxCoins(vector<int>& nums) {
        int n = nums.size();
        nums.push_back(1);
        nums.insert(nums.begin() , 1);
        vector<vector<int>>dp(nums.size(), vector<int>(nums.size(), -1));
        return helper(nums, 1, nums.size() - 2, dp);
    }
};
// You are given an integer array nums and an integer goal.

// You want to choose a subsequence of nums such that the sum of its elements is the closest possible to goal. That is, if the sum of the subsequence's elements is sum, then you want to minimize the absolute difference abs(sum - goal).

// Return the minimum possible value of abs(sum - goal).

// Note that a subsequence of an array is an array formed by removing some elements (possibly all or none) of the original array.

// We cannot use dp as sum can also be negative and we cannot store negative index for iterative dp.

//n <= 40 we use the technique of meet in the middle when n size <= 50 for such type of questions.
// we divide the array in two hafles of equal size and generate all possible subsequence of both the array now since size reduce to half.
// after that we want first[i] + second[j] to be closet to goal so we can achieve this using binary search or two pointer.

class Solution {
public:
    vector<int> helper(vector<int>&v)
    {
        vector<int>res;
         int n=v.size();   
        for(int i=0;i<(1<<n);i++)
        {   
            int sum=0;
            for(int j=0;j<n;j++)
            {
                if(i&(1<<j)){sum+=v[j];}
            }
            res.push_back(sum);
        }
        return res;
    }
    int minAbsDifference(vector<int>& nums, int goal) {
        vector<int>first, second;
        int n = nums.size();
        vector<int>A,B;
        for(int i=0;i<n/2;i++)A.push_back(nums[i]);
        for(int i=n/2;i<n;i++)B.push_back(nums[i]);
        first = helper(A);
        second = helper(B);
        int ans = INT_MAX;
        sort(first.begin(),first.end());
        sort(second.begin(), second.end());
        int l = 0, r= second.size() - 1;
        while(l < first.size()  && r >= 0)
        {
            int s = first[l] + second[r];
            ans = min(ans, abs(goal - s));
            if(s > goal)
            {
               r--;
            }
            else if(s < goal)
            l++;
            else
            break;
        }
        return ans;
    }
};

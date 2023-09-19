// Given an array of integers nums containing n + 1 integers where each integer is in the range [1, n] inclusive.

// There is only one repeated number in nums, return this repeated number.

// You must solve the problem without modifying the array nums and uses only constant extra space.
// All the integers in nums appear only once except for precisely one integer which appears two or more times.

// It can be easily implemented by sorting or HashMap or changing the given array but here it want to solve it in O(1) without changing the array.


// Binary Search Solution

class Solution {
public:
    int findDuplicate(vector<int>& nums) {
      int low=0;
        int high=nums.size()-1;
        int ans = 0;
        while(low<=high)
        {
            int mid=(low+high)/2;
            int count=0;
            for(int i=0;i<nums.size();i++)
            {
                if(nums[i]<=mid)
                    count++;
            }
            if(count>mid)
            {
                ans = mid;
                high=mid - 1;
            }
            else
                low=mid+1;
        }
        return ans;
    }
};
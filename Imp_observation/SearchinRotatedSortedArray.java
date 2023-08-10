// There is an integer array nums sorted in non-decreasing order (not necessarily with distinct values).

// Before being passed to your function, nums is rotated at an unknown pivot index k (0 <= k < nums.length) such that the resulting array is [nums[k], nums[k+1], ..., nums[n-1], nums[0], nums[1], ..., nums[k-1]] (0-indexed). For example, [0,1,2,4,4,4,5,6,6,7] might be rotated at pivot index 5 and become [4,5,6,6,7,0,1,2,4,4].

// Given the array nums after the rotation and an integer target, return true if target is in nums, or false if it is not in nums.

// You must decrease the overall operation steps as much as possible.

// Problem Link : https://leetcode.com/problems/search-in-rotated-sorted-array-ii/description/
class Solution {
    public boolean search(int[] nums, int target) {
         int l = 0;
         int r = nums.length - 1;
         while(l <= r)
         {
             int mid = (l + r) / 2;
             if(nums[mid] == target)
             {
                 return true;
             }
             // case like nums = [6,6,6,6,6,6,6,6] target = 9 then time compleaxity is O(n) -> Worst Case
             if(nums[mid] == nums[l])
             {
                l++;
                continue;
             }
             // here we are checking whether target and start ele belongs to the same side of the array left or right
             // left -> rotated part right -> not rotated part.
             // if belongs to differen side then we enter inside the if block
             if( ( nums[l] <= target ) ^ (nums[mid] >= nums[l]) )
             {
                 // mid is in the left part so target should be in right half and vice versa.
                 if(nums[mid] >= nums[l])
                 {
                    l = mid + 1;
                 }
                 else
                 {
                     r = mid - 1;
                 }
             }
             else
             {
                //this is the case when both lie in the same side so we only need to decide according to the 
                //comparison with target
                    if(nums[mid] > target)
                    {
                    r = mid - 1;
                    }
                    else
                    {
                    l = mid + 1;
                    }
             }
         }
         return false;
    }
}
// You are given a 0-indexed array nums comprising of n non-negative integers.

// In one operation, you must:

// Choose an integer i such that 1 <= i < n and nums[i] > 0.
// Decrease nums[i] by 1.
// Increase nums[i - 1] by 1.
// Return the minimum possible value of the maximum integer of nums after performing any number of operations.
//Brute force
/*
[3,7,1,6]
One set of optimal operations is as follows:
1. Choose i = 1, and nums becomes [4,6,1,6].
2. Choose i = 3, and nums becomes [4,6,2,5].
3. Choose i = 1, and nums becomes [5,5,2,5].
The maximum integer of nums is 5. It can be shown that the maximum number cannot be less than 5.
Therefore, we return 5.
/*
Binary Search
/*
 1st -> we can do it by brute force we try to decrease the greatest no every time till we able to decrease the ele in the array
 if we not able to decrease the ele then that is our ans. T.C -> (n*(max_ele));
 2nd -> we can do it by binary search the range is min is arr[0]-> because we can not decrease this ele r = max_ele in the array
 and for checking whether this will be the possible ans or not start from back and if ele is greater than possible ans then add ele - mid
 to prev ele and at last check if arr[0] <= poss_ans then we move to the left otherwise move to the right;
*/
// Prefix Sum
// we are taking max because the min ans is arr[0] and it will only increase and we only transfer value to the left so we are taking
// max at every index and we are taking avg because we can distribute the value among i ele. 
class Solution {
    public int minimizeArrayValue(int[] nums) {
        int ans = nums[0];
        double prefixSum = nums[0];
        for(int i = 1; i < nums.length; i++)
        {
           prefixSum += nums[i];
           int avg = (int)Math.ceil(prefixSum / (i + 1));
           ans = Math.max(ans, avg);
        }
        return ans;
    }
}
 
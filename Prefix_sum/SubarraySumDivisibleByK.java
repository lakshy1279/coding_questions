// Given an integer array nums and an integer k, return the number of non-empty subarrays that have a sum divisible by k.
// A subarray is a contiguous part of an array.
// Input: nums = [4,5,0,-2,-3,1], k = 5
// Output: 7
// Explanation: There are 7 subarrays with a sum divisible by k = 5:
// [4, 5, 0, -2, -3, 1], [5], [5, 0], [5, 0, -2, -3], [0], [0, -2, -3], [-2, -3]
// in the Prefix Sum array our task is to determine the number of pairs (i, j) where i < j and (prefixSum[j] - prefix[i]) % k = 0. This equality can only be true if prefixSum[i] % k = prefixSum[j] % k.

class Solution {
    public int subarraysDivByK(int[] nums, int k) {
        HashMap<Integer, Integer> reminder = new HashMap<>();
        int sum = 0;
        int ans = 0;
        reminder.put(0, 1); // add this to handle the case when sum is divisible by k.
        for(int i = 0; i < nums.length; i++)
        {
            sum += nums[i];
            int rem = ( sum % k + k) % k;
            if(reminder.containsKey(rem))
            {
                ans += reminder.get(rem);
                reminder.put(rem, reminder.get(rem) + 1);
            }
            else
            reminder.put(rem, 1);
        }
        return ans;
    }
}
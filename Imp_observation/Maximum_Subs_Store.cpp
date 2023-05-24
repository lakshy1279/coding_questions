// You are given two 0-indexed integer arrays nums1 and nums2 of equal length n and a positive integer k. You must choose a subsequence of indices from nums1 of length k.

// For chosen indices i0, i1, ..., ik - 1, your score is defined as:

// The sum of the selected elements from nums1 multiplied with the minimum of the selected elements from nums2.
// It can defined simply as: (nums1[i0] + nums1[i1] +...+ nums1[ik - 1]) * min(nums2[i0] , nums2[i1], ... ,nums2[ik - 1]).
// Return the maximum possible score.

// A subsequence of indices of an array is a set that can be derived from the set {0, 1, ..., n-1} by deleting some or no elements.

//Recall the definition of the score, the second term has been fixed as nums2[i], so we can maximzie the total score by maximizing the first term, that is, by selecting the maximum k elements from nums1 including nums1[i].
//we should not start from last index of the soretd array becuase then time complexity will be n^2;
// After sorting Pairs array we should observe that at any index we have to found the max k-1 ele from index -1 to 0;
// we create a pair of nums2 , nums1 because when we select the ele from nums2 then we should also have to select the same index ele in nums1.

class Solution {
public:
    long long maxScore(vector<int>& nums1, vector<int>& nums2, int k) {
       int n = nums2.size();
       pair<int,int> nums3[n];
       for(int i = 0; i < n; i++)
       {
         nums3[i] = {nums2[i], nums1[i]};
       }
       sort(nums3, nums3 + n);
       reverse(nums3, nums3 + n);
       long long ans = 0;
       long long sum = 0;
       priority_queue<int, vector<int>, greater<int>>pq;
       for(int i = 0; i < n; i++)
       {
          sum += nums3[i].second;
          pq.push(nums3[i].second);
          if(pq.size() == k)
          {
              ans = max(ans, sum * nums3[i].first);
              sum -= pq.top();
              pq.pop();
          }
       }
       return ans;
    }
};
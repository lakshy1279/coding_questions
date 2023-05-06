// You are given an array of integers nums and an integer target.

// Return the number of non-empty subsequences of nums such that the sum of the minimum and maximum element on it is less or equal to target. Since the answer may be too large, return it modulo 109 + 7.


// one can think of dp so always think properly.
// DP won't work here, the subproblem's max and mini are different for every subproblem when you consider subproblem till an index.


 int getEle(vector<int>& nums, int ele, int l)
    {
        int r = nums.size() - 1;
        while(l <= r)
        {
            int mid = (l + r) / 2;
            if(nums[mid] > ele)
            {
                r = mid - 1;
            }
            else
            l = mid + 1;
        }
        return l;
    }
    int numSubseq(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int mod = 1000000007;
        long long ans = 0;
        int n = nums.size();
        int power[n];
        power[0] = 1;
        for (int i = 1; i < n; ++i) {
            power[i] = (power[i - 1] * 2) % mod;
        }
        // we can also solve this without binary search using only two pointer.
        // if(nums[i] + nums[j] > target) then j is of no use so we do j--
        // if(nums[i] + nums[j] <= targte) in this case we can make subsequece with i as the min_ele 2^(j - i) and then do i++;
        for(int i = 0; i < nums.size(); i++)
        {
           int value = target - nums[i];
           if(value <= 0)
           continue;
           int upper1 = getEle(nums, value, i) - 1;
           cout<<upper1 <<" "<< i<<endl;
          if(upper1 >= i)
          {
           int ele = upper1 - i;
           ans += power[ele];
           ans %= mod;
          }
        }
        return ans;
    }
};
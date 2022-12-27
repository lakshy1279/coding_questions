// link- https://leetcode.com/contest/weekly-contest-325/problems/maximum-tastiness-of-candy-basket/
// In this we are going to ask maximum tastiness so when we have maximum and minmum try to thing of binary search
// In this we know that min tast we get is 0 and max is arr[n-1] - arr[0] so we have a range now for every mid we check whether this may be the possible ans for the given
// k and if it is possile and then we check for higher mid otherwise we reduce the mid;
 bool isPossible(vector<int> &price, int k, int val)
    {
        int pre = price[0];
        k--;
        for(int i = 1; i < price.size(); i++)
        {
            if(price[i] - pre >= val)
            {
                k--;
                pre = price[i];
            }
        }
        return k <= 0;
    }
    int maximumTastiness(vector<int>& price, int k) {
         sort(price.begin(), price.end());
         int n = price.size();
         int l = 0, r = price[n - 1];
         int ans = 0;
         while(l <= r)
         {
             int mid = (l + r) / 2;
             if(isPossible(price, k, mid))
             {
                 l = mid + 1;
                 ans = max(ans, mid);
             }
             else
                 r = mid - 1;
         }
        return ans;
    }

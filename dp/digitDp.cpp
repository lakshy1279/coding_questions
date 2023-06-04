// You are given two numeric strings num1 and num2 and two integers max_sum and min_sum. We denote an integer x to be good if:

// num1 <= x <= num2
// min_sum <= digit_sum(x) <= max_sum.
// Return the number of good integers. Since the answer may be large, return it modulo 109 + 7.

// Note that digit_sum(x) denotes the sum of the digits of x.
// in this we generate all number place wise tight1 and tight2 represent that if tight1 is true then we can not choose the no
// bellow the no present at the current index. simlarly tight2 repesent that if it's is true then we can not choose bigger no then the no present 
// at that index.

using ll = long long;
const ll mod = 1e9 + 7;
class Solution {
    ll dp[23][2][2][401];
    ll countStrings(ll index, bool tight1, bool tight2, string& num1, string& num2, ll sum)
    {
        if(sum < 0)
        return 0;
        if(index == num2.size())
        return 1;
        if(dp[index][tight1][tight2][sum] != -1)
        return dp[index][tight1][tight2][sum];
        ll start = tight1 ? num1[index] - '0' : 0;
        ll end = tight2 ? num2[index] - '0' : 9;
        ll count = 0;
        for(ll idx = start; idx <= end; idx++)
        {
          count = ( count % mod + countStrings(index + 1, ( tight1 & (idx == start) ), 
          ( tight2 & (idx == end) ), num1, num2, sum - idx ));
        }
        return dp[index][tight1][tight2][sum] = count;
    }
    public:
    int count(string num1, string num2, int min_sum, int max_sum) {
        memset(dp, -1, sizeof(dp));
        string numhelper = "";
        int n1 = num1.size();
        int n2 = num2.size();
        int d = n2 - n1;
        while(d-- > 0)
        numhelper += '0';
        numhelper += num1;
        ll a = countStrings(0, 1, 1, numhelper, num2, max_sum);
        ll b = countStrings(0, 1, 1, numhelper, num2, min_sum - 1);
        ll ans = (a - b) % mod;
        return (ans < 0) ? ans + mod : ans;
    }
};
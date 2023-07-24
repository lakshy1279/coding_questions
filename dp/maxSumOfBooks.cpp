// You are given an array books representing the number of books placed on a shelf, where books[i] represents the number of books at position i on the shelf. You want to take some books from the shelf while following these constraints:

// You can take any number of books from a single position on the shelf.
// You take book only from continguous section and take books in increasing fashion like arr[i + 1] > arr[i];
// Find the maximum sum of books that you can take from the shelf while adhering to the given constraints.

//Asked in Many OA (Amazon)


// Brute Force

int ans = 0;
// n -> size of the book shelf books[]
for(int i = n - 1; i >= 0; i--)
{
   int value = books[i];
   for(int j = i - 1; j >= 0; j--)
   {
     value += min(books[j] , books[i] - (i - j));
   }
   ans = max(ans, value);
}

//books[j] >= books[i] - (i - j) then we take books[i] - (i - j)
// books[j] < books[i] - (i - j) then we need to take books[j]

// books[j] - j >= books[i] - i
// now for every index i we need to find the j such that books[j] - j < books[i] - i

 long long maximumBooks(vector<int>& books) {
        int n = books.size();
        vector<int> nums(n);
        for (int i = 0; i < n; ++i) nums[i] = books[i] - i;
        vector<int> left(n, -1);
        stack<int> stk;
        // precomputing the j for every 
        for (int i = 0; i < n; ++i) {
            while (!stk.empty() && nums[stk.top()] >= nums[i]) stk.pop();
            if (!stk.empty()) left[i] = stk.top();
            stk.push(i);
        }
        vector<ll> dp(n);
        dp[0] = books[0];
        ll ans = books[0];
        for (int i = 1; i < n; ++i) {
            int v = books[i]; // last term of seq
            int j = left[i];
            int cnt = min(v, i - j); // no of continuous ele 
            int u = v - cnt + 1; // first term of the seq
            ll s = 1ll * (u + v) * cnt / 2;
            dp[i] = s + (j == -1 ? 0 : dp[j]);
            ans = max(ans, dp[i]);
        }
        return ans;
 }
// this is the imp question of sliding window technique
// in this we need to take at least k occurence of each character a,b,c by removing minimum character from left and right from the string.
// Find the maximum window size of the string such that count of all A,B,C chars in rest of the string is atleast K


 int takeCharacters(string s, int k) {
        unordered_map<char,int>count;
        for(int i = 0; i < s.size(); i++)
        {
            count[s[i]]++;
        }
        if(count['a'] < k || count['b'] < k || count['c'] < k)
            return -1;
        int i = 0, j = 0;
        int size = s.size();
        int ans = INT_MAX;
        while(i < size)
        {
            count[s[i]]--;
            while(count['a'] < k || count['b'] < k || count['c'] < k)
            {
                count[s[j]]++;
                j++;
            }
            i++;
            ans = min(ans, j + (size - i));
        }
        return ans;
    }

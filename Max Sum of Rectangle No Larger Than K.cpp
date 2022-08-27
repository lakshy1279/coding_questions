class Solution {
public:
    int maxSumSubmatrix(vector<vector<int>>& matrix, int k) {
        int res = INT_MIN;
        int rows = matrix.size();
        int col = matrix[0].size();
        for(int l = 0 ; l < col ; l++)
        {
            vector<int>sums(rows);
            for( int r = l ; r < col ; r++)
            {
                int maxsum = INT_MIN , currsum = 0 ;
                for( int i = 0 ; i < rows ; i++ )
                {
                    sums[i] += matrix[i][r];
                    currsum = max( currsum + sums[i], sums[i]);
                    maxsum = max( maxsum, currsum);
                }
               // kadene algorithm does not work in every case because we do not consider sum < 0 in kadene but it will be possible in this case. might be k is -1;
                if( k >= maxsum)
                {
                    res = max( res, maxsum);
                    continue;
                }
                set<int>st = {0};
                int runsum = 0;
              // we can not use sliding window for that part because it has negative no also and it might be possible that on addition of negative no we get our ans.
                for( auto sum : sums)
                {
                    runsum+=sum;
                    // lower_bound give number just greater than or equal to that no
                    auto it = st.lower_bound(runsum - k);
                    if( it != st.end() )
                    {
                       res =  max(res, runsum - *it);
                    }
                    st.insert(runsum);
                }
            }
        }
        return res;
    }
};

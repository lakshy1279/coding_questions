
        int n = nums.size() ;
        unordered_map<int,int>index ;
        int j = 1 ;
        for(int num : nums) 
        {
            index[num] = j++ ;
        }
        
        for( int i = 0 ; i < n ; )
        {
            if( nums[i] == i + 1 ) i++ ;
            else
            {
                int idx = index[i+1] - 1 ;
                if( idx >= 0 )
                {
                    swap(nums[idx],nums[i++]) ;
                }
                else
                {
                    return i + 1 ;
                }
            }
        }
        
        return n + 1 ;

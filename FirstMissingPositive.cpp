
        
//in this we swap the element with its index position if we not able to find the element corresponding to the index then this index is our ans.
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

..O(1) space solution 
int n=nums.size();
        for( int i=0;i<n;i++ )
            while(nums[i]>0&&nums[i]<=n&&nums[i]!=nums[nums[i]-1]) --checking whether element exist within the range and it is not in the correct position.
                swap(nums[i],nums[nums[i]-1]);
        for(int i=0;i<n;i++)
        {
            if(nums[i]==i+1)
                continue;
             else
                 return i+1;
        }
        return n+1;

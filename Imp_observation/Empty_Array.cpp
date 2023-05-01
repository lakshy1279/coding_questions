// ques -> You are given an integer array nums containing distinct numbers, and you can perform the following operations until the array is empty:

// If the first element has the smallest value, remove it
// Otherwise, put the first element at the end of the array.
// Return an integer denoting the number of operations it takes to make nums empty.
//       0 1 2 3 4 5
// Ex : [3,2,4,1,6,5] 
// sort indexs according to array -> [3,1,0,2,5,4]  now the first ele to remove is on index 3 and second ele on index 1
// 3 > 1 so we to delete 1 we need to shift 3,2,4(3 operation) to the back and delete 1(1 operation) -> 6,5,3,2,4
// since 3 > 1 so we need to to shift 6,5
// so we need to shift n-1 ele and delete 1 ele so no of operation = n;
// 1, 0, 2, 5, 4 sinnce 1 > 0 so again 5 operation need to perform 3,2,4,6,5 -> 2,4,6,5,3 -> 4,6,5,3 -> 3,4,6,5
// 0,2,5,4 since 0 < 2 so move forward because we delete this in one go no need to rotate whole array
// 0,2,5,4 since 2 < 5 so same again
// 0,2,5,4 since 5 > 4 so 4 operation 3,4,6,5 -> 4,6,5 -> 6,5 -> 5, 6 -> 6
// 4 so single ele is remainign so 1 operation;
// agar first index ki value second index se bdi hai to hme total n operation karne padege becuase hme same array ki need hogi next
// ele delete karne ke liye.

class Solution {
public:
    long long countOperationsToEmptyArray(vector<int>& nums) {
         vector<int>index;
        int n = nums.size();
        for(int i = 0; i < n; i++)
            index.push_back(i);
        sort(index.begin(), index.end(), [&](int a, int b){
           return nums[b] > nums[a]; 
        });
        for(int i = 0; i < n; i++)
            cout<<index[i]<<" ";
        int currele = index[0];
        int i = 1;
        int  count = 1;
        long long ans = 0;
        int totalele = n;
        while(i < n)
        {
            if(currele > index[i])
            {
                ans += totalele;
                currele = index[i];
                totalele-=count;
                count = 1;
                i++;
            }
            else
            {
                count++;
                currele = index[i];
                i++;
            }
        }
        ans += count;
        return ans;
    }
};
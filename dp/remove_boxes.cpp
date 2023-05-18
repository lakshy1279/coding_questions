// You are given several boxes with different colors represented by different positive numbers.

// You may experience several rounds to remove boxes until there is no box left. Each time you can choose some continuous boxes with the same color (i.e., composed of k boxes, k >= 1), remove them and get k * k points.

// Return the maximum points you can get.

// Ex: 1,2,1,2,1
// 1st -> 1*1 -> 2nd (1,1) 3rd -> (2,2)
// Ex: 1,3,3,4,3,1

class Solution {
public:
    int highestvalue(vector<int>& boxes,int i,int j,int k,int dp[101][101][101])
    {
        if(i>j)
            return 0;
        if(dp[i][j][k]>0)
            return dp[i][j][k];
        int res=(k+1)*(k+1)+highestvalue(boxes,i+1,j,0,dp);
        for(int m=i+1;m<=j;m++)
        {
            if(boxes[i]==boxes[m])
            {
                res=max(res,highestvalue(boxes,i+1,m-1,0,dp)+highestvalue(boxes,m,j,k+1,dp));
            }
        }
        dp[i][j][k]=res;
        return res;
    }
    int removeBoxes(vector<int>& boxes) {
         int dp[101][101][101]={0};
        return highestvalue(boxes,0,boxes.size()-1,0,dp);
    }
};
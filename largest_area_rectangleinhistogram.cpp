class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        stack<int>st;
        int i=0;
        int n=heights.size();
        int maxarea=0;
        while(i<n)
        {
            //if height is greater than st.top() than then we push it the stack because prev varible can contribute to the area and if height is less than greater height inside the stack is useless it can be contribute to the area only 
            // this insdex from the index of the element
            if(st.empty()||heights[st.top()]<=heights[i])
            {
                st.push(i++);
            }
            else
            {
                int curr=st.top();
                st.pop();
                int area=heights[curr]*(st.empty()?i:i-st.top()-1);
                if(area>maxarea)
                    maxarea=area;                
            }
        }
        while(!st.empty())
        {
            int curr=st.top();
            st.pop();
            int area=heights[curr]*(st.empty()?n:n-st.top()-1);
            if(area>maxarea)
                maxarea=area;
        }
        return maxarea;
    }
};

class Solution {
public:
    //采用84题题解
    int maximalRectangle(vector<vector<char>>& matrix) 
    {
        int rows = matrix.size(),ans = 0;

        if(rows == 0)
            return 0;

        int cols = matrix[0].size();

        vector<int> heights(cols,0);//用于存每一列中连续1的个数

        for(int i = 0;i<rows;i++)
        {
            for(int j = 0;j<cols;j++)
            {
                if(matrix[i][j] == '1')
                    heights[j] ++;
                else//一旦某一列出现1不连续就为0
                    heights[j] = 0;
            }

            ans = max(ans,largestRectangleArea(heights));
        }

        return ans;
    }

    int largestRectangleArea(vector<int> heights)
    {
        //添加哨兵，让最后栈一定会弹出,首尾添加一个0
        heights.insert(heights.begin(),0);
        heights.push_back(0);

        int nums = heights.size(),ans = 0;
        stack<int> st;//用来存储下标，单调栈

        for(int i = 0;i<nums;i++)
        {
            while(!st.empty() && heights[i]<heights[st.top()])//连续查找栈中的元素，直到遇到比当前小的元素，如果栈中元素比当前i所在的值大，则继续弹栈
            {
                int cur = st.top();
                st.pop();
                int left = st.top();
                int right = i;

                ans = max(ans,(right - left -1)*heights[cur]);
            }
            st.push(i);
        }
     /*   
        for(int j = 0;j<nums;j++)
        {
            printf("%d ",heights[j]);
        }
        printf("   %d \n",ans);
    */
        return ans;
    }
};
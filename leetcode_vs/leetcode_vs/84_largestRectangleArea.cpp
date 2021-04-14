class Solution {
public:
    //暴力破解 失败
    int largestRectangleArea(vector<int>& heights) {

        int nums = heights.size();
        int ans = 0;

        for(int i = 0;i<nums;i++)
        {
            int left = 0,right=0;

            //寻找左边界
            for(left = i-1;left>=0;left--)
            {
                if(heights[left]>= heights[i])
                    continue;
                else
                    break;
            }

            for(right = i+1;right<nums;right++)
            {
                if(heights[right]>= heights[i])
                    continue;
                else
                    break;
            }

            ans = max(ans,(right-left-1)*heights[i]);
        }

        return ans;
    }
    
    //单调栈+哨兵
    int largestRectangleArea(vector<int>& heights)
     {

        heights.insert(heights.begin(),0);
        heights.push_back(0);

        stack<int> st;//单调栈，值不断增大

        int nums = heights.size();
        int ans = 0;

        for(int i = 0;i<nums;i++)
        {
            /*
            if(!st.empty())
            {
                int cur = st.top(),left = 0,right = 0;
                if(heights[cur] > heights[i])
                {
                    st.pop();
                    left = st.top();
                    right = i;
                    ans = max(ans,(right-left-1)*heights[cur]);
                }
            }
            */
            //从栈中找比i所在的值小的，直到栈中剩下的值小于当前i所在的值为止
            while(!st.empty() && heights[st.top()] > heights[i])
            {
                int cur = st.top();
                st.pop();
                int left = st.top();
                int right = i;
                ans = max(ans,(right - left -1)*heights[cur]);
            }

            st.push(i);
        }

        return ans;
     }
    
};
#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
	//暴力求解，求每一位数对应的左边最大值和右边最大值，当前位置能够接到的水是 min（左边最大值，右边最大值）- 该位的值
	int trap(vector<int>& height) 
	{
		int len = height.size();
		int left = 0,right=0,left_max = 0,right_max=0,ans = 0;

		for (int i =1;i<len;i++)
		{
			//每一次 最大值，最小值需要清零，需注意
			left_max = 0;
			right_max=0;
			for (int j = i-1;j>=0;j--)
			{
				left_max = max(left_max,height[j]);
			}

			for (int k=i+1;k<len;k++)
			{
				right_max = max(right_max,height[k]);
			}

			ans += max(0,min(left_max,right_max)-height[i]);
		}

		return ans;
	}

	//空间换时间的方法，把每一位的对应左边最大值和右边最大值保存下来
	int trap_1(vector<int>& height) 
	{
		int len = height.size();
		int left = 0,right=0,ans = 0;

		if (len == 0)
		{
			return ans;
		}

		vector<int> left_max(len),right_max(len);

		left_max[0] = height[0];
		for (int i =1;i<len;i++)
		{
			left_max[i] = max(left_max[i-1],height[i]);	
		}

		right_max[len-1] = height[len -1];

		for (int j = len - 2;j>=0;j--)
		{
			right_max[j] = max(right_max[j+1],height[j]);	
		}

		for (int k = 1;k<len-1;k++)
		{
			ans += max(0,min(left_max[k],right_max[k])-height[k]);
		}
		
		return ans;
	}

	//双指针法，左右同时遍历
	//当某一位的left_max <= right_max,则意味着，不管右边还有多大的值，该位都能装水 left_max-height[i]
	//相反，当某一位的left_max > right_max,则意味着，不管左边边还有多大的值，该位都能装水 right_max-height[i]
	int trap_2(vector<int>& height) 
	{
		int len = height.size(),ans = 0;
		if (len == 0)
		{
			return ans;
		}

		int left = 1,right=len-2,left_max = height[0],right_max=height[len-1];
		while (left <= right)
		{
			if (left_max <= right_max)
			{
				ans += max(0,left_max - height[left]);
				left_max = max(left_max,height[left]);
				left++;
			}
			else
			{
				ans += max(0,right_max - height[right]);
				right_max = max(right_max,height[right]);
				right--;
			}
		}

		return ans;
	}
};

int main()
{
	Solution s;
	vector<int> nums;
	nums.push_back(4);
	nums.push_back(2);
	nums.push_back(0);
	nums.push_back(3);
	nums.push_back(2);
	nums.push_back(5);

	int res = s.trap_1(nums);

	system("pause");

	return 0;
}
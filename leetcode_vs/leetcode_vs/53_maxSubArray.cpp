#include <iostream>
#include <vector>
#include <string>
#include <stack>
#include <algorithm>
#include <map>

using namespace std;

class Solution {
public:
	//采用动态规划，dp[]每一位表示已下标i为结束的最大子序和
	int maxSubArray(vector<int>& nums) 
	{
		int  len = nums.size(),ans = nums[0],pre_max=nums[0];

		if (len==1)
		{
			return ans;
		}

		for (int i = 1;i<len;i++)
		{
			pre_max = max(pre_max+nums[i],nums[i]);
			ans = max(pre_max,ans);
		}

		return ans;
	}
};

#if 0
int main()
{
	Solution s;
	vector<int> nums;
	nums.push_back(-2);
	nums.push_back(1);
	nums.push_back(-3);
	nums.push_back(4);
	nums.push_back(-1);
	nums.push_back(2);
	nums.push_back(1);
	nums.push_back(-5);
	nums.push_back(4);

	int ret = s.maxSubArray(nums);

	system("pause");

	return 0;
}

#endif
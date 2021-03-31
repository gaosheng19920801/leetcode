#include <iostream>
#include <vector>
#include <string>
#include <stack>
#include <algorithm>
#include <map>

using namespace std;
class Solution {
public:
	//采用动态规划
	bool canJump(vector<int>& nums) 
	{
		int len = nums.size();
		vector<bool> dp(len,false);
		dp[0] = true;

		for (int i =1;i<len;i++)
		{
			if (dp[i-1])
			{
				for (int k = 0;k<nums[i-1];k++)
				{
						dp[i+k] = true;
				}
			}
			else
			{
				dp[i] = false;
				break;
			}
		}
		
		return dp[len-1];
	}

	bool canJump_1(vector<int>& nums) 
	{
		int cur_max = 0,len = nums.size();

		for (int i=0;i<len;i++)
		{
			if (i<=cur_max)
			{
				cur_max = max(i+nums[i],cur_max);
				if (cur_max >=len-1)
				{
					return true;
				}
			}else
				break;
		}

		return false;
	}
};

#if 0
int main()
{
	Solution s;
	vector<int> nums;
	nums.push_back(2);
	nums.push_back(3);
	nums.push_back(1);
	nums.push_back(1);
	nums.push_back(4);

	bool ret = s.canJump_1(nums);

	system("pause");

	return 0;
}

#endif
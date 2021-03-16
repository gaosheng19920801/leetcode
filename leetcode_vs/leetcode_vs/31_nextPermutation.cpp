#include <iostream>
#include <vector>
#include <string>
#include <queue>
using namespace std;

class Solution {
public:
	void nextPermutation(vector<int>& nums) {
		int len = nums.size();
		if (len == 0 || len ==1)
			return;

		int i=len-2,j= len-1;
		for (;i >= 0 && nums[i] >= nums[j];j--,i--)
		{
		}

		if(i >= 0)
		{
			for (int m = len-1;m >i;m--)
			{
				if (nums[i] < nums[m])
				{
					swap(nums[i],nums[m]);
					break;
				}
			}	
		}

		for (int k = len -1;k > j;j++,k--)
		{
			swap(nums[j],nums[k]);
		}
	}
};

#if 0
int main()
{
	vector<int> nums;
	nums.push_back(1);
	nums.push_back(3);
	nums.push_back(2);
	Solution s;
	s.nextPermutation(nums);
	return 0;
}
#endif
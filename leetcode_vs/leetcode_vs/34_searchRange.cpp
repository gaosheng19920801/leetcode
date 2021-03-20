#include <iostream>
#include <vector>
#include <string>
#include <stack>

using namespace std;

class Solution {
public:
	vector<int> searchRange(vector<int>& nums, int target) 
	{
		int len = nums.size();
		vector<int> ret;
		ret.push_back(-1);
		ret.push_back(-1);
		if (len == 0)
		{
			return ret;
		}

		int leftBoard = getLeftBoard(nums,target);

		if (leftBoard == -1)
			return  ret;

		ret[0] = leftBoard;

		int rightBoard = getRightBoard(nums,target);
		ret[1] = rightBoard;

		return ret;
	}

	int getLeftBoard(vector<int>& nums, int target)
	{
		int len = nums.size(),l = 0,r=len-1,leftBoard = -1;

		while (l<=r)
		{
			int mid = (l+r)/2;

			if (nums[mid] > target)//位于左侧
			{
				r = mid-1;
			}
			else if (nums[mid] < target)//位于右侧
			{
				l = mid+1;
			}
			else//nums[mid] == target
			{
				leftBoard = mid;
				r = mid-1;
			}
		}

		return leftBoard;
	}

	int getRightBoard(vector<int>& nums, int target)
	{
		int len = nums.size(),l = 0,r=len-1,rightBoard = -1;

		while (l<=r)
		{
			int mid = (l+r)/2;

			if (nums[mid] > target)//位于左侧
			{
				r = mid-1;
			}
			else if (nums[mid] < target)//位于右侧
			{
				l = mid+1;
			}
			else//nums[mid] == target
			{
				rightBoard = mid;
				l = mid+1;
			}
		}

		return rightBoard;
	}
};


int main()
{
	Solution s;
	vector<int> nums;
	nums.push_back(4);
	nums.push_back(5);
	nums.push_back(5);
	nums.push_back(7);
	nums.push_back(7);
	nums.push_back(8);

	vector<int> ret = s.searchRange(nums,7);


	system("pause");

	return 0;
}
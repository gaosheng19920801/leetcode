#include <iostream>
#include <vector>
#include <string>
#include <stack>

using namespace std;
class Solution {
public:
	int search(vector<int>& nums, int target) {
		int len = nums.size() ;
		if (len == 1)
		{
			return nums[0] == target?0:-1;
		}

		for (int i = 0;i<len;i++)
		{
			if (target == nums[i])
			{
				return i;
			}
		}

		return -1;
	}

	int search_1(vector<int>& nums, int target) {
		int len = nums.size() ;
		if (len == 1)
		{
			return nums[0] == target?0:-1;
		}
		int l = 0,r=len-1;
		while (l<=r)
		{
			int mid = (l+r)/2;

			if (nums[mid] == target)
			{
				return mid;
			}
			if (nums[l] <= nums[mid])//��������� һ��ҪС�ڵ��ڣ�����Ϊ������������ʱ��������
			{
				if (target< nums[mid] && target>=nums[l])
				{
					r = mid -1;
				}
				else
				{
					l = mid+1;
				}
			}
			else//�ұ�������
			{
				if (target> nums[mid] && target<=nums[r])
				{
					l =  mid+1;
				}
				else
				{
					r = mid-1;
				}
			}

		}
		return -1;
	}
};

int main()
{
	Solution s;


	system("pause");

	return 0;
}
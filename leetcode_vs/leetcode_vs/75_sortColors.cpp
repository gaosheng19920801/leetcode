#include <iostream>
#include <vector>
#include <string>
#include <stack>
#include <algorithm>

using namespace std;

class Solution {
public:
	//方法一：采用计数排序，先统计0，1，2各有多少个，再对数组重新赋值
	void sortColors_1(vector<int>& nums) {
		int zero = 0,one = 0,two = 0;

		for(int i = 0;i<nums.size();i++)
		{
			if(nums[i] == 0)
			{
				zero++;
				continue;
			}

			if(nums[i] == 1)
			{
				one++;
				continue;
			}

			if(nums[i] == 2)
			{
				two++;
				continue;
			}
		}

		for(int i=0;i<nums.size();i++)
		{
			if(i<zero)
			{
				nums[i] = 0;
				continue;
			}

			if(i<zero+one)
			{
				nums[i] = 1;
				continue;
			}

			if(i<zero+one+two)
			{
				nums[i] = 2;
				continue;
			}
		}
	}

	//双指针法
	void sortColors_2(vector<int>& nums) 
	{
		int len = nums.size();
		int ptr_0 = 0,ptr_2 = len-1,i = 0;

		while(i <= ptr_2)
		{
			if(nums[i] == 0)
			{
				nums[i] = nums[ptr_0];
				nums[ptr_0] = 0;
				ptr_0++;
				printf("i= %d,pre_0 = %d,pre_2=%d ",i,ptr_0,ptr_2);
				printNums(nums);
			}

			if(nums[i] == 2)
			{
				nums[i] = nums[ptr_2];
				nums[ptr_2] = 2;
				ptr_2--;
				if (nums[i] != 1)//不为1时需要回退 此处是关键
					i--;

				printf("i= %d,pre_0 = %d,pre_2=%d ",i,ptr_0,ptr_2);
				printNums(nums);
			}
			i++;

		}
	}

	void printNums(vector<int>& nums)
	{
		for(auto i=nums.begin();i!=nums.end();i++)
			printf("%d", *i);
		printf("\n");
	}
};



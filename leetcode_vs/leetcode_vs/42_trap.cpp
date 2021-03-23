#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
	//������⣬��ÿһλ����Ӧ��������ֵ���ұ����ֵ����ǰλ���ܹ��ӵ���ˮ�� min��������ֵ���ұ����ֵ��- ��λ��ֵ
	int trap(vector<int>& height) 
	{
		int len = height.size();
		int left = 0,right=0,left_max = 0,right_max=0,ans = 0;

		for (int i =1;i<len;i++)
		{
			//ÿһ�� ���ֵ����Сֵ��Ҫ���㣬��ע��
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

	//�ռ任ʱ��ķ�������ÿһλ�Ķ�Ӧ������ֵ���ұ����ֵ��������
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

	//˫ָ�뷨������ͬʱ����
	//��ĳһλ��left_max <= right_max,����ζ�ţ������ұ߻��ж���ֵ����λ����װˮ left_max-height[i]
	//�෴����ĳһλ��left_max > right_max,����ζ�ţ�������߱߻��ж���ֵ����λ����װˮ right_max-height[i]
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
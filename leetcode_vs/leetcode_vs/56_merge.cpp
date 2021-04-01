#include <iostream>
#include <vector>
#include <string>
#include <stack>
#include <algorithm>

using namespace std;

class Solution {
public:
	//������Ȼ�����������ұ�ֵ����ĳ��������ֵ���������ֵʱ��Ϊһ������
	vector<vector<int>> merge(vector<vector<int>>& intervals) 
	{
		sort(intervals.begin(),intervals.end());
		vector<vector<int>> res;
		int left = intervals[0][0],right_max = intervals[0][1],len = intervals.size();

		if (len==1)
		{
			return intervals;        
		}

		for (int i = 1;i<len;i++)
		{
			if (intervals[i][0] > right_max)
			{
				vector<int> temp;
				temp.push_back(left);
				temp.push_back(right_max);
				res.push_back(temp);

				left = intervals[i][0];
				right_max = intervals[i][1];
			}
			else
			{
				right_max = max(right_max,intervals[i][1]);
			}

			if(i == len-1)//�õط���Ҫ���ǵ����λ��ʱҪ��δ���
			{
				right_max = max(right_max,intervals[i][1]);
				vector<int> temp;
				temp.push_back(left);
				temp.push_back(right_max);
				res.push_back(temp);
			}
		}

		return res;

	}
};


#if 0
int main()
{
	Solution s;
	vector<int> nums;
	nums.push_back(1);
	nums.push_back(2);
	nums.push_back(3);

	s.print_result(s.permute(nums));

	system("pause");

	return 0;
}
#endif
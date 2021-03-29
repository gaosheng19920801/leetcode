#include <iostream>
#include <vector>
#include <string>
#include <stack>
#include <algorithm>

using namespace std;

class Solution {
public:
	vector<vector<int>> combinationSum(vector<int>& candidates, int target)
	{
		int len = candidates.size();

		vector<vector<int>>* res = new vector<vector<int>>;
		if (len == 0)
		{
			return *res;
		}

		vector<int> cur_path;

		sort(candidates.begin(),candidates.end());//排序后可以进行剪枝，提高运行效率
		dfs(candidates,target,0,len,&cur_path,res);

		return *res;
	}

	void dfs(vector<int>& nums,int target,int begin,int len,vector<int> *cur_path,vector<vector<int>>* res)
	{
		if (target == 0)
		{
			vector<int> path = *cur_path;
			res->push_back(path);
		}

		for (int i = begin;i<len;i++)//从begin开始是为了避免重复的，指定begin则已经用过的就不再加入
		{
			if (target-nums[i] < 0)//剪枝处理
			{
				return;
			}

			cur_path->push_back(nums[i]);

			dfs(nums,target-nums[i],i,len,cur_path,res);

			cur_path->pop_back();
		}
	}

	void print_result(vector<vector<int>> res)
	{
		for (vector<vector<int>>::iterator i=res.begin();i<res.end();i++ )
		{
			for (vector<int>::iterator j = i->begin();j < i->end();j++)
			{
				cout<<*j<<"";
			}
			cout <<endl;
		}
	}
};

#if 0
int main()
{
	Solution s;
	vector<int> nums;
	nums.push_back(2);
	nums.push_back(3);
	nums.push_back(4);
	nums.push_back(5);

	vector<vector<int>> res = s.combinationSum(nums,7);

	s.print_result(res);

	system("pause");

	return 0;
}
#endif
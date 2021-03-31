#include <iostream>
#include <vector>
#include <string>
#include <stack>

using namespace std;

class Solution {
public:
	//采用树结构进行回溯
	vector<vector<int>> permute(vector<int>& nums) 
	{
		int len = nums.size(),depth=0;
		vector<int> path,status(len,0);
		vector<vector<int>> *res = new vector<vector<int>> ;

		dfs(nums,0,len,&path,&status,res);

		return *res;		
	}

	void dfs(vector<int>& nums,int depth,int len,vector<int> *cur_path,vector<int> *status,vector<vector<int>> *res)
	{
		if(depth == len)//当深度等于数组长度时说明已经到了二叉树最底部，需要将当前的path加入到结果中
		{
			vector<int> path = *cur_path;//因为函数内部如果不进行copy的话，出了函数，cur_path中的值就被释放了
			res->push_back(path);
		}

		for (int i = 0;i<len;i++)
		{
			if (status->at(i) == 0)
			{
				cur_path->push_back(nums[i]);
				status->at(i) = 1;//状态置1
				dfs(nums,depth+1,len,cur_path,status,res);//进入下一层
				cur_path->pop_back();
				status->at(i) = 0;
			}
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
#include <iostream>
#include <vector>
#include <string>
#include <stack>
#include <algorithm>

using namespace std;

class Solution {
public:

	//先左下三角和右上三角进行交换，再左右进行交换
	void rotate(vector<vector<int>>& matrix) 
	{
		int n = matrix.size();
		for (int i = 0;i<n;i++)
		{
			for (int j = i+1;j<n;j++)
			{
				swap(matrix[i][j],matrix[j][i]);
			}
		}

		for (int k=0;k< n;k++)
		{
			for(int t = 0;t<n/2;t++)//这个地方边界处理需注意不能等于
			{
				swap(matrix[k][t],matrix[k][n-1-t]);
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
#if 0
int main()
{
	Solution s;
	vector<int> nums;
	nums.push_back(2);
	nums.push_back(3);
	nums.push_back(4);
	nums.push_back(5);

	s.print_result(res);

	system("pause");

	return 0;
}
#endif
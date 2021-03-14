#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
	vector<string> res;
	int count;
	vector<string> generateParenthesis(int n)
	{
		if (n == 0)
			return res;

		count = 0;

		dfs("",n,n);

		return res;
	}
private:
	void dfs(string cur_str,int left,int right)
	{
		if (left == 0 && right == 0)
		{
			res.push_back(cur_str);
			count ++;
			return;
		}

		if (right < left)
			return;

		if (left > 0)
			dfs(cur_str + "(",left-1,right);

		if (right > 0)
			dfs(cur_str + ")",left,right-1);
	}
};



int main()
{
	Solution s;

	s.generateParenthesis(5);
	cout<<s.count<<endl;

	for (vector<string>::const_iterator iter = s.res.begin();iter != s.res.end();iter++)
	{
		cout << *iter <<endl;
	}

	system("pause");
	return 0;
}
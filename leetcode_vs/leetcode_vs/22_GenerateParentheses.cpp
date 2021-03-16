#include <iostream>
#include <vector>
#include <string>
#include <queue>
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

class Solution2 {
	class Node
	{
	public:
		string cur_str;
		int left;
		int right;

		Node(string str,int left_num,int right_num)
		{
			cur_str = str;
			left = left_num;
			right = right_num;
		}
	};

public:
	vector<string> res;
	queue<Node> queue;
	
	int count;
	vector<string> generateParenthesis(int n)
	{
		if (n == 0)
			return res;

		count = 0;
		
		Node node("",n,n);
		queue.push(node);

		while (!queue.empty())
		{
			Node cur_node = queue.front();
			queue.pop();

			if (cur_node.left == 0 && cur_node.right == 0)
			{
				res.push_back(cur_node.cur_str);
				continue;
			}

			if (cur_node.left > 0)
			{
				Node node(cur_node.cur_str+'(',cur_node.left-1,cur_node.right);
				queue.push(node);
			}

			if (cur_node.right > 0 && cur_node.left < cur_node.right)
			{
				Node node(cur_node.cur_str+')',cur_node.left,cur_node.right-1);
				queue.push(node);
			}
		}

		return res;
	}
};
#if 0
int main()
{
	//Solution s;
	Solution2 s;

	s.generateParenthesis(5);
	cout<<s.count<<endl;

	for (vector<string>::const_iterator iter = s.res.begin();iter != s.res.end();iter++)
	{
		cout << *iter <<endl;
	}

	system("pause");
	return 0;
}

#endif
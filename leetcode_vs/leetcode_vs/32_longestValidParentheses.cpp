#include <iostream>
#include <vector>
#include <string>
#include <stack>

using namespace std;

class Solution {
public:
	//动态规划
	int longestValidParentheses(string s) {
		int len = 0;
		int *dp = new int[s.size()+1];//dp为以当前i所在的字符为结束的最长括号长度
		dp[0] = 0;
		for (int i = 1;i<s.size();i++)
		{
			dp[i] = 0;
			if (s[i] == ')')
			{
				if (i-2 >= 0 && s[i-1] == '(')
				{
					dp[i] = dp[i-2] +2;
				}
				else
				{
					if (i-dp[i-1] -1 >= 0 && s[i-dp[i-1] -1] == '(')
					{
						dp[i] = dp[i-1]+ 2;

						if (i-dp[i-1]-2 >= 0)
						{
							dp[i] = dp[i]+dp[i-dp[i-1]-2];
						}
					}
				}
			}

			len = max(len,dp[i]);
		}
		delete[] dp;

		return len;
	}

	//使用堆栈
	int longestValidParentheses_1(string s)
	{
		int s_len = s.size();
		if  (s_len == 0)
		{
			return 0;
		}
		stack<int> s_index;//用于存括号所在的下标
		
		int len = 0,last = -1;

		s_index.push(-1);

		for (int i = 0;i<s_len;i++)
		{
			if (s[i] == ')')
			{
				if (!s_index.empty())
				{
					int index = s_index.top();

					if (index != -1 && s[index] == '(')
					{
						s_index.pop();

						if (s_index.top() != -1)
						{
							len = max(len,i-s_index.top());
						}
						else
						{
							len = max(len,i+1);
						}

						continue;
					}
				}
			}
			s_index.push(i);
		}
		return len;
	}

};


#if 0
int main()
{
	Solution s;
	string str = ")()()))";
	//int len = s.longestValidParentheses(str);
	int len = s.longestValidParentheses_1(str);
	cout<<len<<endl;

	system("pause");

	return 0;
}
#endif
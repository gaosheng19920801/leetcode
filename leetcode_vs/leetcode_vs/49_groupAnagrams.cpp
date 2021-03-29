#include <iostream>
#include <vector>
#include <string>
#include <stack>
#include <algorithm>
#include <map>

using namespace std;

class Solution {
public:
	//�ȶ�ÿ���ַ�������������ͬ���ַ����������ͬ�����������ַ�����Ϊ���ŵ�hash����
	vector<vector<string>> groupAnagrams(vector<string>& strs) 
	{
		map<string,vector<string>> map;

		for (int i=0;i<strs.size();i++)
		{
			string str = strs[i];
			sort(str.begin(),str.end());//����ط���Ҫע����strȥ������
			map[str].push_back(strs[i]);
		}

		vector<vector<string>> res;

		for (auto it = map.begin();it != map.end();it++)
		{
			res.push_back(it->second);
		}
		
		return res;
	}

	void print_result(vector<vector<string>> res)
	{
		for (vector<vector<string>>::iterator i=res.begin();i<res.end();i++ )
		{
			for (vector<string>::iterator j = i->begin();j < i->end();j++)
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
	//vector<int> nums;
	//nums.push_back(2);
	//nums.push_back(3);
	//nums.push_back(4);
	//nums.push_back(5);

	//s.print_result(res);

	system("pause");

	return 0;
}
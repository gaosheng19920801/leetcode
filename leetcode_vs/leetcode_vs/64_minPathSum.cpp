#include <iostream>
#include <vector>
#include <string>
#include <stack>
#include <algorithm>

using namespace std;

class Solution {
public:
	int minPathSum(vector<vector<int>>& grid) {
		int row = grid.size();
		int clonum = grid[0].size();

		vector<vector<int>> dp(row,vector<int>(clonum));

		dp[0][0] = grid[0][0];
		int i = 0,j = 0;

		for(i = 1;i<row;i++)
		{
			dp[i][0] = dp[i-1][0]+grid[i][0];
		}

		for(j = 1;j<clonum;j++)
		{
			dp[0][j] = dp[0][j-1]+grid[0][j];
		}

		for(i =1;i< row;i++)
		{
			for(j = 1;j<clonum;j++)
			{
				dp[i][j] = min(dp[i-1][j],dp[i][j-1]) + grid[i][j];
			}
		}

		return dp[row-1][clonum-1];
	}
};
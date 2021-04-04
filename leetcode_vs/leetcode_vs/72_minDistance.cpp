#include <iostream>
#include <vector>
#include <string>
#include <stack>
#include <algorithm>

using namespace std;

class Solution {
public:
    int minDistance(string word1, string word2) {
        int len_1 = word1.length(),len_2 = word2.length(),i = 0,j = 0;
      //  printf("%d %d",len_1,len_2);
        //dp[i][j]表示word1从0到i的字符串转化成word2中0到j字符串所需的最少操作数
        vector<vector<int>> dp(len_1+1,vector<int>(len_2+1,0));
        //""空字符串到word2的转换最少操作
        for(i = 0;i<=len_2;i++)
        {
            dp[0][i] = i;
        }

        for(i = 0;i<=len_1;i++)
        {
            dp[i][0] = i;
        }

        for(i=1;i<=len_1;i++)
        {
            for(j=1;j<=len_2;j++)
            {
                if(word1[i-1] == word2[j-1])
                {
                    dp[i][j] = dp[i-1][j-1];
                }
                else
                {
                    dp[i][j] = min(min(dp[i-1][j],dp[i][j-1]),dp[i-1][j-1])+1;
                }
            }
        }

        return dp[len_1][len_2];
    }
};
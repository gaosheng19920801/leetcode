#include <iostream>
#include <vector>
#include <string>
#include <stack>
#include <algorithm>

using namespace std;

class Solution {
public:
    int climbStairs(int n) {
        if (n==1)
            return 1;
        
        if(n==2)
            return 2;

       // vector<int> dp(n,0);
       // dp[0] = 1;
      //  dp[1] = 2;

        int pre_1=2,pre_2 = 1,cur = 0;

        for(int i=2;i<n;i++)
        {
           // dp[i] = dp[i-1]+dp[i-2];
            cur = pre_1+pre_2;
            pre_2 = pre_1;
            pre_1 = cur;
        }

       // return dp[n-1];
       return cur;
    }
};
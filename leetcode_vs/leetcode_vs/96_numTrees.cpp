class Solution {
public:
    //动态规划
    int numTrees(int n) {
        vector<int> dp(n+1,0);
        dp[0] = 1;
        dp[1] = 1;
        //dp[n]等于分别以1到n为根节点的二叉树数目的和，当以i为根节点时，其种类为左子树的种类*右子树的种类
        //左子树节点个数  右节点个数
        //    0            i-1
        //    1            i-2
        //    ....         ....
        //    i-1           0
        for(int i=2;i<=n;i++)
        {
            for(int j = 0;j<i;j++)
                dp[i] += dp[j]*dp[i-j-1];
        }
        return dp[n];
    }
};
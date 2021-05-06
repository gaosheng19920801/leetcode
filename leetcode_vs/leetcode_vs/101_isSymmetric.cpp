/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
//参考链接https://leetcode-cn.com/problems/symmetric-tree/solution/dong-hua-yan-shi-101-dui-cheng-er-cha-shu-by-user7/
class Solution {
public:
    //递归解法 对称的二叉树 左节点的左节点和右节点的右节点相等 以及 左节点的右节点和右节点的左节点相等
    bool dfs(TreeNode* left,TreeNode* right)
    {
        if(left == nullptr && right == nullptr)
            return true;
        
        if(left == nullptr || right == nullptr)
            return false;

        if(left->val != right->val)
            return false;

        return dfs(left->left,right->right) && dfs(left->right,right->left);
    }
    
    bool isSymmetric(TreeNode* root) {

        if(root == nullptr)
            return false;

        return dfs(root->left,root->right);
    }
    
    
   //非递归解法 采用队列 依次将左节点的左节点和右节点的右节点 以及 左节点的右节点和右节点的左节点 同时入队列
    bool isSymmetric(TreeNode* root) {
        if(root == nullptr)
            return false;

        queue<TreeNode*> q;
        q.push(root->left);
        q.push(root->right);

        while(!q.empty())
        {
            TreeNode* left = q.front();
            q.pop();
            TreeNode* right = q.front();
            q.pop();

            if(left==nullptr && right == nullptr)
                continue;
            
            if(left==nullptr || right == nullptr)
                return false;

            if(left->val != right->val)
                return false;

           //依次将左节点的左节点和右节点的右节点 以及 左节点的右节点和右节点的左节点 同时入队列
            q.push(left->left);
            q.push(right->right);
            q.push(left->right);
            q.push(right->left);

        }

        return true;
    }
};
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
class Solution {
public:
    long pre = LONG_MIN;
    /*递归方式，中序遍历，当前节点一定比上一个节点小*/
    bool isValidBST_1(TreeNode* root) 
    {
        if(root == nullptr)
            return true;

        if(!isValidBST(root->left))
            return false;

        if(root->val <= pre)
            return false;

        pre = root->val;

        return isValidBST(root->right);
    }
    
     /*非递归方式，中序遍历，当前节点一定比上一个节点小*/
    bool isValidBST(TreeNode* root) 
    {
        stack<TreeNode*> st;
        long pre = LONG_MIN;

        while(root != nullptr || !st.empty())//当节点不为空或者栈不为空时进行循环
        {
            //找到最左边节点
            while(root != nullptr)
            {
                st.push(root);
                root = root->left;
            }

            //到达最左边节点，当前节点root为空，需要从栈中取出数据
            root = st.top();
            st.pop();
            if(root->val <= pre)//中序遍历是递增
                return false;
            pre = root->val;
            root = root->right;
        }

        return true;
    }
    
    
    //莫里斯遍历
    bool isValidBST(TreeNode* root) 
    {
        long pre = LONG_MIN;

        while(root != nullptr)
        {
           if(root->left != nullptr)//左子树不为空时，将root以及其右子树放到root的左子树的最右节点后面
           {
               TreeNode* pre = root->left;
               while(pre->right != nullptr)
               {
                   pre = pre->right;
               }

               //此时到达左子树的最右节点，进行节点变换
               pre->right = root;
               root = root->left;
               pre->right->left = nullptr;//将之前的root的左子树变为空
           }
           else//左侧已经没有节点，说明到了最右边，可以进行比较
           {
               if(root->val <= pre)
                    return false;

                pre = root->val;
                
                root = root->right;
           }
        }

        return true;
    }
    
    
};






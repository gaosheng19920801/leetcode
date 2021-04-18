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
    //递归
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> path;

        if(root!=NULL)
            inorder(root,path);

        return path; 

    }

    void inorder(TreeNode* root,vector<int>& path)
    {
        if(root == NULL)
            return;
        
        inorder(root->left,path);
        path.push_back(root->val);
        inorder(root->right,path);
    }
    
     //使用栈遍历
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> path;
        stack<TreeNode*> st;

        while(root != nullptr|| !st.empty())
        {
            while(root != nullptr)//先找到最左边,所有的节点都要入栈后再弹出
            {
                st.push(root);
                root = root->left;
            }
            root = st.top();
            st.pop();
            path.push_back(root->val);
            root = root->right;
        }

        return path; 
    }
	
	//莫里斯遍历 
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> res;

        while(root != nullptr)
        {
            if(root->left != nullptr)//左子树不为空时，将root放到左子树的最右边节点尾部
            {
               TreeNode* pre = root->left;
                //找到左节点的最右边节点
                while(pre->right != nullptr)
                {
                    pre = pre->right;
                }
                //将root放到最右边节点后面，同时切换root为左节点
                pre->right = root;
                TreeNode* temp = root->left;//注意该地方需要对左节点先进行保存
                root->left = nullptr;
                root = temp;
            }
            else//左子树为空时添加至输出
            {
                res.push_back(root->val);
                root = root->right;//root为当前节点的右子树
            }
        }

        return res;
    }
	
	//莫里斯遍历 双百解
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> res;

        while(root != nullptr)
        {
            if(root->left != nullptr)//左子树不为空时，将root放到左子树的最右边节点尾部
            {
               TreeNode* pre = root->left;
                //找到左节点的最右边节点
                while(pre->right != nullptr)
                {
                    pre = pre->right;
                }
                //将root放到最右边节点后面，同时切换root为左节点
                pre->right = root;
               // TreeNode* temp = root->left;
              //  root->left = nullptr;
                root = root->left;
                pre->right->left = nullptr;
            }
            else//左子树为空时添加至输出
            {
                res.push_back(root->val);
                root = root->right;//root为当前节点的右子树
            }
        }

        return res;
    }

};
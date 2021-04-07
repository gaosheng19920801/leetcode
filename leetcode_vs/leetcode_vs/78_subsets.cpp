class Solution {
public:
    //采用回溯算法，需要找到状态位
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> res;//用于记录最终结果
        vector<int> path;//用于记录当前路径

        int len = nums.size();
        backFind(nums,path,res,0);
        return res;
    }

    void backFind(vector<int>& nums,vector<int>& path,vector<vector<int>> &res, int start)
    {
        //每到达一个节点时，将当前元素加到路径中
        res.push_back(path); 
        for(int i = start;i<nums.size();i++)
        {
            path.push_back(nums[i]); //一定要在这个地方进行添加 否则回溯会出现问题
            backFind(nums,path,res,i+1);
            path.pop_back();
        }
    }
};
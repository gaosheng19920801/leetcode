class Solution {
public:
    bool dfs(vector<vector<char>>& board,vector<vector<int>>& visited,int i,int j, string word,int index)
    {
        //结束判断
        if(board[i][j] != word[index])
        {
            return false;
        }
        else if(index == word.size()-1)//已经找到
        {
            return true;
        }
        
        //访问位置1
        visited[i][j] = 1;
        //当当前元素找到后进行以下操作

        //定义四个方向上的操作,上，下，左，右
        vector<pair<int,int>> directions = {{-1,0},{1,0},{0,-1},{0,1}};
        for(auto dir:directions)
        {
            int newi = i+dir.first,newj = j+dir.second;

            if(newi>=0 && newi <board.size() && newj >= 0 && newj<board[0].size())
            {
                if(visited[newi][newj] == 0)
                {
                    bool flg = dfs(board,visited,newi,newj,word,index+1);

                    if(flg)
                    {
                        //访问位置0
                        visited[i][j] = 0;
                        return true;
                    }
                }
                
            }
        }

        //访问位置0
        visited[i][j] = 0;
        return false;
    }

    bool exist(vector<vector<char>>& board, string word) 
    {
        int row = board.size(), column = board[0].size();

        //用于保存元素是否被访问过
        vector<vector<int>> visited(row,vector<int>(column,0));

        for(int i=0;i<row;i++)
        {
            for(int j=0;j<column;j++)
            {
                bool res = dfs(board,visited,i,j,word,0);

                if(res)//一旦找到则返回，否则继续
                {
                    return true;
                }
            }
        }

        return false;

    }

};
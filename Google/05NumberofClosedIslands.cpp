// 1254. Number of Closed Islands
// Given a 2D grid consists of 0s (land) and 1s (water).  An island is a maximal 4-directionally connected group of 0s and a closed island is an island totally (all left, top, right, bottom) surrounded by 1s.
// Return the number of closed islands.
// Example 1:
// Input: grid = [[1,1,1,1,1,1,1,0],[1z0,0,0,0,1,1,0],[1,0,1,0,1,1,1,0],[1,0,0,0,0,1,0,1],[1,1,1,1,1,1,1,0]]
// Output: 2
// Explanation: 
// Islands in gray are closed because they are completely surrounded by water (group of 1s).
// Example 2:

// Input: grid = [[0,0,1,0,0],[0,1,0,1,0],[0,1,1,1,0]]
// Output: 1
class Solution {
public:  
    void dfs(int i, int j,vector<vector<int>>& board ,int r, int c)
        
    {
        if(i<0 ||  i>=r|| j<0 || j>=c || board[i][j]!=0)
        {
            return;
            
        }
        
        if(board[i][j]==0)
        {    
        board[i][j]=-1;
            
        }
        
        dfs(i-1,j,board,r,c);
        dfs(i+1,j,board,r,c);
        dfs(i,j-1,board,r,c);
        dfs(i,j+1,board,r,c);
        
        
        
    }
    
    
    int closedIsland(vector<vector<int>>&board) {
        int cnt=0;
        
           int r = board.size();
        int c = board[0].size();
        
        for(int j=0;j<c;j++)
        {
            if(board[0][j]==0)
            {
                dfs(0,j,board,r,c);
            }
        }
        
           for(int j=0;j<c;j++)
        {
            if(board[r-1][j]==0)
            {
                dfs(r-1,j,board,r,c);
            }
        }
        
              for(int i=0;i<r;i++)
        {
            if(board[i][0]==0)
            {
                dfs(i,0,board,r,c);
            }
        }
        
              for(int i=0;i<r;i++)
        {
            if(board[i][c-1]==0)
            {
                dfs(i,c-1,board,r,c);
            }
        }
        
        
        for(int i=0;i<r;i++)
        {
            for(int j=0;j<c;j++)
            {
                if(board[i][j]==0)
                {
                    cnt++;
                    dfs(i,j,board,r,c);
                    
                }
            }
        }return cnt;
    }
    
    
};

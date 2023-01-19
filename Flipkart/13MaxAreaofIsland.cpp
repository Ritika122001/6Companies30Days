// 695. Max Area of Island
// You are given an m x n binary matrix grid. An island is a group of 1's (representing land) connected 4-directionally (horizontal or vertical.) You may assume all four edges of the grid are surrounded by water.

// The area of an island is the number of cells with a value 1 in the island.

// Return the maximum area of an island in grid. If there is no island, return 0.
// Example 1:
// Input: grid = [[0,0,1,0,0,0,0,1,0,0,0,0,0],[0,0,0,0,0,0,0,1,1,1,0,0,0],[0,1,1,0,1,0,0,0,0,0,0,0,0],[0,1,0,0,1,1,0,0,1,0,1,0,0],[0,1,0,0,1,1,0,0,1,1,1,0,0],[0,0,0,0,0,0,0,0,0,0,1,0,0],[0,0,0,0,0,0,0,1,1,1,0,0,0],[0,0,0,0,0,0,0,1,1,0,0,0,0]]
// Output: 6
// Explanation: The answer is not 11, because the island must be connected 4-directionally.
// Example 2:

// Input: grid = [[0,0,0,0,0,0,0,0]]
// Output: 0
class Solution {
public:

    int solve(vector<vector<int>>& grid, int i , int j)
    {
        if(i<0 || j<0 || i>=grid.size() || j>=grid[0].size()|| grid[i][j]==2 || grid[i][j]==0)
        {
            return 0;
        }

        grid[i][j]=2;

       return 1 + solve(grid,i+1,j) + solve(grid,i-1,j) + solve(grid,i,j+1) + solve(grid,i,j-1);
        

    }

    int maxAreaOfIsland(vector<vector<int>>& grid) {

int cnt=0;
        for(int i=0 ; i<grid.size();i++)
        {
            for(int j=0;j<grid[0].size();j++)
            {
                if(grid[i][j]==1)
                {
                    int ans=0;
                    cnt=max(cnt,solve(grid,i,j));
                }
            }
        }

        return cnt;
        
    }
};

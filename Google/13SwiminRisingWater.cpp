// 778. Swim in Rising Water
// You are given an n x n integer matrix grid where each value grid[i][j] represents the elevation at that point (i, j).

// The rain starts to fall. At time t, the depth of the water everywhere is t. You can swim from a square to another 4-directionally adjacent square if and only if the elevation of both squares individually are at most t. You can swim infinite distances in zero time. Of course, you must stay within the boundaries of the grid during your swim.

// Return the least time until you can reach the bottom right square (n - 1, n - 1) if you start at the top left square (0, 0).
// Example 1:
// Input: grid = [[0,2],[1,3]]
// Output: 3
// Explanation:
// At time 0, you are in grid location (0, 0).
// You cannot go anywhere else because 4-directionally adjacent neighbors have a higher elevation than t = 0.
// You cannot reach point (1, 1) until time 3.
// When the depth of water is 3, we can swim anywhere inside the grid.
  
// Example 2:
// Input: grid = [[0,1,2,3,4],[24,23,22,21,5],[12,13,14,15,16],[11,17,18,19,20],[10,9,8,7,6]]
// Output: 16
// Explanation: The final route is shown.
// We need to wait until time 16 so that (0, 0) and (4, 4) are connected.

class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;
        int n = grid.size(), m = grid[0].size();
        int dirx[4] = {1, -1, 0, 0};
        int diry[4] = {0, 0, -1, 1};
        int val = 0;
        pq.push({grid[0][0],{0,0}});
        grid[0][0] = -1;
        while(!pq.empty())
        {
            int sz = pq.size();
            while(sz--)
            {
                pair<int, pair<int, int>> r = pq.top();
                int x = r.second.first, y = r.second.second;
                pq.pop();
                val = max(val, r.first);
                if(x == n-1 && y == m-1) return val;
                for(int i = 0; i < 4; i++)
                {
                    int nxtx = x + dirx[i];
                    int nxty = y + diry[i];
                    if(nxtx < 0 || nxtx >= n || nxty < 0 || nxty >= m) continue;
                    if(grid[nxtx][nxty] == -1) continue;
                    pq.push({grid[nxtx][nxty],{nxtx, nxty}});
                    grid[nxtx][nxty] = -1;
                }
            }
        }
        return val;
    }
};

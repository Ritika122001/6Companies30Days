// 1878. Get Biggest Three Rhombus Sums in a Grid
// You are given an m x n integer matrix grid​​​.

// A rhombus sum is the sum of the elements that form the border of a regular rhombus shape in grid​​​. The rhombus must have the shape of a square rotated 45 degrees with each of the corners centered in a grid cell. Below is an image of four valid rhombus shapes with the corresponding colored cells that should be included in each rhombus sum:
// Note that the rhombus can have an area of 0, which is depicted by the purple rhombus in the bottom right corner.
// Return the biggest three distinct rhombus sums in the grid in descending order. If there are less than three distinct values, return all of them.

// Example 1:
// Input: grid = [[3,4,5,1,3],[3,3,4,2,3],[20,30,200,40,10],[1,5,5,4,1],[4,3,2,2,5]]
// Output: [228,216,211]
// Explanation: The rhombus shapes for the three biggest distinct rhombus sums are depicted above.
// - Blue: 20 + 3 + 200 + 5 = 228
// - Red: 200 + 2 + 10 + 4 = 216
// - Green: 5 + 200 + 4 + 2 = 211

// Example 2:
// Input: grid = [[1,2,3],[4,5,6],[7,8,9]]
// Output: [20,9,8]
// Explanation: The rhombus shapes for the three biggest distinct rhombus sums are depicted above.
// - Blue: 4 + 2 + 6 + 8 = 20
// - Red: 9 (area 0 rhombus in the bottom right corner)
// - Green: 8 (area 0 rhombus in the bottom middle)
// Example 3:

// Input: grid = [[7,7,7]]
// Output: [7]
// Explanation: All three possible rhombus sums are the same, so return [7].

class Solution {
public:
    int solve(vector<vector<int>>& grid,int l,int r,int u,int d){
        int c1 = (l+r)/2,c2=(l+r)/2,sum=0;
        bool flag = true;

        for(int row = u;row<=d;row++)
        {
            if(c1 == c2) sum += grid[row][c1];
            else sum += grid[row][c1] + grid[row][c2];
            if(c1 == l && c2==r) flag = false;
            if(flag) c1--,c2++;
            else c1++,c2--;
        }

        return sum;
    }

    vector<int> getBiggestThree(vector<vector<int>>& grid) {
        int m = grid.size(),n=grid[0].size();
        set<int> st;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                int l=j,r=j,d=i; 
                while(l>=0 && r<n && d<m){
                    int sum = solve(grid,l,r,i,d);
                    l--; r++; d += 2;
                    if(st.size() < 3) st.insert(sum);
                    else if(st.size() == 3 && st.count(sum)==0 && sum > *(st.begin())) {
                        st.erase(st.begin());
                        st.insert(sum);
                    }
                }
            }
        }

        vector<int> ans;
        for(int it : st){
            ans.push_back(it);
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};

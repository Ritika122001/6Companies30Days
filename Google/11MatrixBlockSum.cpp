// 1314. Matrix Block Sum
// Medium
// 2.1K
// 323
// Companies
// Given a m x n matrix mat and an integer k, return a matrix answer where each answer[i][j] is the sum of all elements mat[r][c] for:

// i - k <= r <= i + k,
// j - k <= c <= j + k, and
// (r, c) is a valid position in the matrix.
 

// Example 1:

// Input: mat = [[1,2,3],[4,5,6],[7,8,9]], k = 1
// Output: [[12,21,16],[27,45,33],[24,39,28]]
// Example 2:

// Input: mat = [[1,2,3],[4,5,6],[7,8,9]], k = 2
// Output: [[45,45,45],[45,45,45],[45,45,45]]

class Solution {
public:
    vector<vector<int>> matrixBlockSum(vector<vector<int>>& mat, int k) {
    int row = mat.size();
    int col = mat[0].size();
    vector<vector<int>> temp(row+1,vector<int>(col+1,0));
    for(int i=1;i<=row;i++){
        for(int j=1;j<=col;j++){
            temp[i][j] = temp[i-1][j] + temp[i][j-1] - temp[i-1][j-1];
            temp[i][j] += mat[i-1][j-1];
        }
    }
    
    vector<vector<int>> ans = mat;
    
    for(int i=0;i<row;i++){
        for(int j=0;j<col;j++){
            int x = max(0,i-k);
            int y = max(0,j-k);
            int c = min(row,i+k+1);
            int d = min(col,j+k+1);
            ans[i][j] = temp[c][d] - temp[c][y] - temp[x][d] + temp[x][y];
        }
    }
    
    return ans;
}
};

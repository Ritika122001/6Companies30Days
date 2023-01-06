// 593. Valid Square
// Given the coordinates of four points in 2D space p1, p2, p3 and p4, return true if the four points construct a square.
// The coordinate of a point pi is represented as [xi, yi]. The input is not given in any order.
// A valid square has four equal sides with positive length and four equal angles (90-degree angles).

// Example 1:

// Input: p1 = [0,0], p2 = [1,1], p3 = [1,0], p4 = [0,1]
// Output: true
// Example 2:

// Input: p1 = [0,0], p2 = [1,1], p3 = [1,0], p4 = [0,12]
// Output: false
// Example 3:

// Input: p1 = [1,0], p2 = [-1,0], p3 = [0,1], p4 = [0,-1]
// Output: true
 
class Solution {
public:
    bool validSquare(vector<int>& p1, vector<int>& p2, vector<int>& p3, vector<int>& p4) 
    {

        vector<vector<int>> pts = {p1, p2, p3, p4};
        set<int>st;
        for(int i=0;i<pts.size();i++)
        {

            for(int j=i+1;j<pts.size();j++)
            
            {
                int x = pow((pts[j][0] - pts[i][0]) ,2);
                int y = pow((pts[j][1] - pts[i][1]) ,2);
                int sq = (x+y);
                // mp[sq]++;
                st.insert(sq);
            
        }

        }

   
        return !st.count(0) && st.size() == 2;

    }
};
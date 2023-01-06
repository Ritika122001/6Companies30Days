// 149. Max Points on a Line
// Given an array of points where points[i] = [xi, yi] represents a point on the X-Y plane, return the maximum number of points that lie on the same straight line.


// Example 1:


// Input: points = [[1,1],[2,2],[3,3]]
// Output: 3
// Example 2:


// Input: points = [[1,1],[3,2],[5,3],[4,1],[2,3],[1,4]]
// Output: 4

class Solution {
public:
    int maxPoints(vector<vector<int>>& points) {

        int n=points.size();
        if(n<=2) return n;
        int ans = 0;

        for(int i=0;i<points.size();i++)
        {
             unordered_map<double,int>mp;


            for(int j=i+1;j<points.size();j++)
            {

                if(points[i] == points[j]) continue;
                
                double slope;
                double nemo = points[j][1] - points[i][1];
                double deno = points[j][0] - points[i][0];

                if(deno==0)
                {
                    slope = INT_MAX;
                }

                else{
                    slope = nemo/ deno; 

                }

                mp[slope]++;
                ans = max(ans, mp[slope]);

                


            }
        }

        return ans+1;
        
    }
};
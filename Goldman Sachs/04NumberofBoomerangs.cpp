// 447. Number of Boomerangs
// You are given n points in the plane that are all distinct, where points[i] = [xi, yi]. A boomerang is a tuple of points (i, j, k) such that the distance between i and j equals the distance between i and k (the order of the tuple matters).

// Return the number of boomerangs.


// Example 1:

// Input: points = [[0,0],[1,0],[2,0]]
// Output: 2
// Explanation: The two boomerangs are [[1,0],[0,0],[2,0]] and [[1,0],[2,0],[0,0]].
// Example 2:

// Input: points = [[1,1],[2,2],[3,3]]
// Output: 2


class Solution {
public:
    int numberOfBoomerangs(vector<vector<int>>& points) 
    {

        int cnt=0;
        for(auto i  : points)
        {
            int x1 = i[0];
            int y1 = i[1];
            int dist=0;
            map<int,int>mp;
            for(auto j : points)
            {

                int x2 = j[0];
                int y2 = j[1];

                dist =  pow((x2-x1),2) + pow((y2-y1),2);
                if(mp.find(dist)!=mp.end())
                {
                    cnt+=mp[dist]*2;
                }

                mp[dist]++;

            }

        }

      return cnt;
        
    }
};

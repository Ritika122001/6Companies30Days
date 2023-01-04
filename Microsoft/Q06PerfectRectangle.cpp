// 391. Perfect Rectangle
// Given an array rectangles where rectangles[i] = [xi, yi, ai, bi] represents an axis-aligned rectangle. The bottom-left point of the rectangle is (xi, yi) and the top-right point of it is (ai, bi).

// Return true if all the rectangles together form an exact cover of a rectangular region.

// Example 1:

// Input: rectangles = [[1,1,3,3],[3,1,4,2],[3,2,4,4],[1,3,2,4],[2,3,3,4]]
// Output: true
// Explanation: All 5 rectangles together form an exact cover of a rectangular region.
// Example 2:

// Input: rectangles = [[1,1,2,3],[1,3,2,4],[3,1,4,2],[3,2,4,4]]
// Output: false
// Explanation: Because there is a gap between the two rectangular regions.

 class Solution {
public:
    bool isRectangleCover(vector<vector<int>> &rectangles)
    {
      if (rectangles.size() == 0 || rectangles[0].size() == 0)
    
        {
            return false;
        }
    
        // int area=0;
        set<pair<int,int>> st; 
        long long area = 0;
    
        for (auto x : rectangles)
        {
            //store the points combination into set 
            pair<int,int> s1{x[0],x[1]};
			pair<int,int> s2{x[2],x[3]};
			pair<int,int> s3{x[0],x[3]};
			pair<int,int> s4{x[2],x[1]};

    
            area += (long long) ((long long)(x[2] - x[0]) * (long long)(x[3] - x[1])); //calculate the area

            //if points exist erase , else insert into set
    
            if (st.find(s1) != st.end())
            {
                st.erase(s1);
            }
            else
            {
                st.insert(s1);
            }
            if (st.find(s2) != st.end())
            {
                st.erase(s2);
            }
            else
            {
                st.insert(s2);
            }
            if (st.find(s3) != st.end())
            {
                st.erase(s3);
            }
            else
            {
                st.insert(s3);
            }
            if (st.find(s4) != st.end())
            {
                st.erase(s4);
            }
            else
            {
                st.insert(s4);
            }
        }

        // if size of set will be equal to 4 and area == calculated area from points exist in set --> return true
        // else false
    
      if(st.size()==4 && area == (long long)((long long)(*st.rbegin()).second-(*st.begin()).second)*((long long)(*st.rbegin()).first-(*st.begin()).first)) return true;
      return false;
     }

};

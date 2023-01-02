// 216. Combination Sum III
// Find all valid combinations of k numbers that sum up to n such that the following conditions are true:

// Only numbers 1 through 9 are used.
// Each number is used at most once.
// Return a list of all possible valid combinations. The list must not contain the same combination twice, and the combinations may be returned in any order.

 

// Example 1:

// Input: k = 3, n = 7
// Output: [[1,2,4]]
// Explanation:
// 1 + 2 + 4 = 7
// There are no other valid combinations.
// Example 2:

// Input: k = 3, n = 9
// Output: [[1,2,6],[1,3,5],[2,3,4]]
// Explanation:
// 1 + 2 + 6 = 9
// 1 + 3 + 5 = 9
// 2 + 3 + 4 = 9
// There are no other valid combinations.


class Solution {
public:

    void solve(int k, int tar , vector<int>&ans, vector<vector<int>>&ds, int idx)
    {

        if(ans.size()==k) //if the size becomes equal to k
        {

            if(tar==0)  //if target value ==0 
            {
                ds.push_back(ans); //push back ans vector into ds vector 
                return;
            }

        }


        for(int i=idx;i<=9;i++) //loop through 1 to 9
        {
            ans.push_back(i); //push the number into ans vector
            solve(k,tar-i,ans,ds,i+1);
            ans.pop_back(); //backtacking --> pop the number from ans vector

        }




    }


    vector<vector<int>> combinationSum3(int k, int n) {

        vector<int>ans;
        vector<vector<int>>ds; 
         solve(k,n,ans,ds,1); 
         return ds; 
        
    }
};
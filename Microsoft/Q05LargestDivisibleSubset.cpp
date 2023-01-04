// 368. Largest Divisible Subset
// Given a set of distinct positive integers nums, return the largest subset answer such that every pair (answer[i], answer[j]) of elements in this subset satisfies:
// answer[i] % answer[j] == 0, or
// answer[j] % answer[i] == 0
// If there are multiple solutions, return any of them.

// Example 1:
// Input: nums = [1,2,3]
// Output: [1,2]
// Explanation: [1,3] is also accepted.
// Example 2:

// Input: nums = [1,2,4,8]
// Output: [1,2,4,8]

class Solution {
public:

  vector<int> temp;
  vector<int> dp;


 void solve(int ind,  vector<vector<int>>&ans, vector<int>&res,vector<int>& nums , int prev)
  {

    if(ind >= nums.size()) 
    {
      if(res.size()>temp.size()) temp=res;
      return;
    }

    if((int)res.size()>dp[ind] && nums[ind]%prev==0) 
    {   dp[ind]=res.size();
 
        res.push_back(nums[ind]);
         solve(ind+1,ans,res,nums,nums[ind]); //move to next index
         res.pop_back(); //backtracking step
    }
    
    solve(ind+1,ans,res,nums,prev);    
    
  }



    vector<int> largestDivisibleSubset(vector<int>& nums) {
      
      sort(nums.begin(),nums.end());
      vector<vector<int>>ans;
      vector<int>res;
     for(int i=0;i<=nums.size();i++) dp.push_back(-1); // Memoization

      solve(0,ans, res,nums,1); 
      return temp;

        
    }
};

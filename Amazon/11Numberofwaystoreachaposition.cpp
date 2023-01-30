// 2400. Number of Ways to Reach a Position After Exactly k Steps
// You are given two positive integers startPos and endPos. Initially, you are standing at position startPos on an infinite number line. With one step, you can move either one position to the left, or one position to the right.

// Given a positive integer k, return the number of different ways to reach the position endPos starting from startPos, such that you perform exactly k steps. Since the answer may be very large, return it modulo 109 + 7.

// Two ways are considered different if the order of the steps made is not exactly the same.

// Note that the number line includes negative integers.
// Example 1:

// Input: startPos = 1, endPos = 2, k = 3
// Output: 3
// Explanation: We can reach position 2 from 1 in exactly 3 steps in three ways:
// - 1 -> 2 -> 3 -> 2.
// - 1 -> 2 -> 1 -> 2.
// - 1 -> 0 -> 1 -> 2.
// It can be proven that no other way is possible, so we return 3.
// Example 2:

// Input: startPos = 2, endPos = 5, k = 10
// Output: 0
// Explanation: It is impossible to reach position 5 from position 2 in exactly 10 steps.

class Solution {
public:
    
    long long int mod =1e9+7;
    
    int solve(int start , int end, int k, vector<vector<int>>&memo)
    {
        if(k==0)
        {
            if(start==end)
            {
                return 1;
            }
            else{
                return 0;
            }
            
        }
        
        if(memo[start+1000][k]!=-1)
        {
            return memo[start+1000][k];
        }

        return memo[start+1000][k] = (solve(start-1,end,k-1,memo)%mod + solve(start+1,end,k-1,memo)%mod)%mod;
        
        
    }
    
    
    int numberOfWays(int start, int end, int k) {
        
        vector<vector<int>>memo(3000, vector<int>(k+1,-1));
        return solve(start,end,k,memo)%mod;
        
    }
};

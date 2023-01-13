// 600. Non-negative Integers without Consecutive Ones
// Given a positive integer n, return the number of the integers in the range [0, n] whose binary representations do not contain consecutive ones.
// Example 1:
// Input: n = 5
// Output: 5
// Explanation:
// Here are the non-negative integers <= 5 with their corresponding binary representations:
// 0 : 0
// 1 : 1
// 2 : 10
// 3 : 11
// 4 : 100
// 5 : 101
// Among them, only integer 3 disobeys the rule (two consecutive ones) and the other 5 satisfy the rule. 
// Example 2:

// Input: n = 1
// Output: 2
// Example 3:

// Input: n = 2
// Output: 3


class Solution {
    int dp[32][2][2];
    int solve(string &s, int idx, bool small, int prev){
        if(idx == s.size())return 1;
        if(dp[idx][small][prev] != -1)return dp[idx][small][prev];
        
        int lmt;
        if(small) lmt = 1;
        else lmt = s[idx]-'0';
        
        int ans = 0;
        for(int i = 0; i <= lmt; i++){
            bool nsmall = small;
            if(i < lmt) nsmall = true;
            
            if(prev != 1 || i != 1){
                ans += solve(s, idx + 1, nsmall, i);
            }
        }
        return dp[idx][small][prev] = ans;
    }
public:
    int findIntegers(int n) {
        string s;
        while(n != 0){
            int rem = n % 2;
            s += rem + '0';
            n = n / 2;
        }
        
        memset(dp, -1, sizeof dp);
        reverse(s.begin(),s.end());
        return solve(s,0,false,0);
    }
};

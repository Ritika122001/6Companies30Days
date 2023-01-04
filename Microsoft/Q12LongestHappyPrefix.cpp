// 1392. Longest Happy Prefix
// A string is called a happy prefix if is a non-empty prefix which is also a suffix (excluding itself).

// Given a string s, return the longest happy prefix of s. Return an empty string "" if no such prefix exists.

// Example 1:

// Input: s = "level"
// Output: "l"
// Explanation: s contains 4 prefix excluding itself ("l", "le", "lev", "leve"), and suffix ("l", "el", "vel", "evel"). The largest prefix which is also suffix is given by "l".
// Example 2:

// Input: s = "ababab"
// Output: "abab"
// Explanation: "abab" is the largest prefix which is also suffix. They can overlap in the original string.

//Used KMP Approach

class Solution {
public:
    string longestPrefix(string s) 
    {
        int n=s.size();
        
        if(n==0)
            return "";
        
        vector<int>prefix(n, 0);
        
        int i=0, j=1;
        
         while(j<n)
         {
            if(s[i]==s[j])
            {
                prefix[j]=i+1;
                i++; j++;
            }
            else
            {
                if(i ==0)
                    j++;
                
                else
                   i = prefix[i-1];
                
            }
        }
        
        return s.substr(0,i);
    }
};
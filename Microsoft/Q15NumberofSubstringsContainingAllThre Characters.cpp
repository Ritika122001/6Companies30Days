1358. Number of Substrings Containing All Three Characters
// Given a string s consisting only of characters a, b and c.

// Return the number of substrings containing at least one occurrence of all these characters a, b and c.
// Example 1:

// Input: s = "abcabc"
// Output: 10
// Explanation: The substrings containing at least one occurrence of the characters a, b and c are "abc", "abca", "abcab", "abcabc", "bca", "bcab", "bcabc", "cab", "cabc" and "abc" (again). 
// Example 2:

// Input: s = "aaacb"
// Output: 3
// Explanation: The substrings containing at least one occurrence of the characters a, b and c are "aaacb", "aacb" and "acb". 
// Example 3:

// Input: s = "abc"
// Output: 1
//Used Sliding Window Approach

class Solution {
public:
    int numberOfSubstrings(string s) {
        int left=0, right=0, count=0, n= s.size()-1 ;
        unordered_map<char, int> mp ;
        
        while(right < s.size()){
            mp[s[right]]++ ;
            
            while(mp['a']  &&  mp['b']  &&  mp['c']){
                count += 1+ (n - right) ;
                
                mp[s[left]]-- ;
                left++ ;
            }
            
            right++ ;
        }
        
        return count ;
    }
};

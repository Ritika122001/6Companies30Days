// 792. Number of Matching Subsequences
// Given a string s and an array of strings words, return the number of words[i] that is a subsequence of s.

// A subsequence of a string is a new string generated from the original string with some characters (can be none) deleted without changing the relative order of the remaining characters.

// For example, "ace" is a subsequence of "abcde".
// Example 1:

// Input: s = "abcde", words = ["a","bb","acd","ace"]
// Output: 3
// Explanation: There are three strings in words that are a subsequence of s: "a", "acd", "ace".
// Example 2:

// Input: s = "dsahjpjauf", words = ["ahjpjau","ja","ahbwzgqnuk","tnmlanowax"]
// Output: 2

class Solution {
public:
bool issubequence(string temp , string &s)
    {
        
       int i=0;
        int j=0;
        
        while(i<temp.length() and j<s.length())
        {
            if(temp[i]==s[j])
            {
                i++;
                j++;
            }
            else{
                j++;
            }
        }
        
        return i==temp.size();
        
        
    }
    
    
    int numMatchingSubseq(string s, vector<string>& words) {
        
        
        //brute force find all subsequence of the string and if present in words array cnt++;

        unordered_map<string,int>ans;
        for(int i=0;i<words.size();i++)
        {
         
            ans[words[i]]++;
        }
        
          int cnt=0;
        
        for(auto c: ans)
        {
            
            if(issubequence(c.first,s))
            {
                cnt+=c.second;
            }
            
        }
        
 
        return cnt;
        
    }
};

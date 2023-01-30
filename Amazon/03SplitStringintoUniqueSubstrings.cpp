// 1593. Split a String Into the Max Number of Unique Substrings
// Given a string s, return the maximum number of unique substrings that the given string can be split into.

// You can split string s into any list of non-empty substrings, where the concatenation of the substrings forms the original string. However, you must split the substrings such that all of them are unique.

// A substring is a contiguous sequence of characters within a string.
// Example 1:

// Input: s = "ababccc"
// Output: 5
// Explanation: One way to split maximally is ['a', 'b', 'ab', 'c', 'cc']. Splitting like ['a', 'b', 'a', 'b', 'c', 'cc'] is not valid as you have 'a' and 'b' multiple times.
// Example 2:

// Input: s = "aba"
// Output: 2
// Explanation: One way to split maximally is ['a', 'ba'].


class Solution {
public:
    
    int ans=1;
    void helper(string &str,int ind,vector<string> &temp,unordered_set<string> &st)
    {
        if(ind == str.length()){
            
            int l=temp.size();
            ans = max(ans,l);
            return;
        }
        string s="";
        for(int i=ind;i<str.length();i++){
            s.push_back(str[i]);
            if(!st.count(s)){                              
                temp.push_back(s);
                st.insert(s);
                helper(str,i+1,temp,st);
                st.erase(s);                         
                temp.pop_back();                    
            }
        }
    }
    int maxUniqueSplit(string s) {
        
        vector<string> temp;
        unordered_set<string> st;
        helper(s,0,temp,st);
        return ans;
        
    }
};

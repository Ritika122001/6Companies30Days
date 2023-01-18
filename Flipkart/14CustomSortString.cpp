// 791. Custom Sort String
// You are given two strings order and s. All the characters of order are unique and were sorted in some custom order previously.

// Permute the characters of s so that they match the order that order was sorted. More specifically, if a character x occurs before a character y in order, then x should occur before y in the permuted string.

// Return any permutation of s that satisfies this property.
// Example 1:
// Input: order = "cba", s = "abcd"
// Output: "cbad"
// Explanation: 
// "a", "b", "c" appear in order, so the order of "a", "b", "c" should be "c", "b", and "a". 
// Since "d" does not appear in order, it can be at any position in the returned string. "dcba", "cdba", "cbda" are also valid outputs.
// Example 2:

// Input: order = "cbafg", s = "abcd"
// Output: "cbad"

class Solution {
public:
    string customSortString(string order, string s) {
        map<int,char> mp;int ind = 0;
        for(auto i:order) mp[ind++]=i;
        unordered_map<char,int> mp1;
        for(auto &i:s) mp1[i]++;
        string ans = "";
        for(auto &i:mp){
            while(mp1[i.second]>0){
                ans+=i.second;
                mp1[i.second]--;
            }
        }
        for(auto &i:mp1){
            while(i.second>0){
                ans+=i.first;
                i.second--;
            }
        }
        return ans;
    }
};

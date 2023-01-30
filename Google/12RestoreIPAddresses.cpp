// 93. Restore IP Addresses
// Companies
// A valid IP address consists of exactly four integers separated by single dots. Each integer is between 0 and 255 (inclusive) and cannot have leading zeros.

// For example, "0.1.2.201" and "192.168.1.1" are valid IP addresses, but "0.011.255.245", "192.168.1.312" and "192.168@1.1" are invalid IP addresses.
// Given a string s containing only digits, return all possible valid IP addresses that can be formed by inserting dots into s. You are not allowed to reorder or remove any digits in s. You may return the valid IP addresses in any order.
// Example 1:

// Input: s = "25525511135"
// Output: ["255.255.11.135","255.255.111.35"]
// Example 2:

// Input: s = "0000"
// Output: ["0.0.0.0"]

class Solution {
public:
    
    bool isvalid(string p)
  {
    int n = p.size();
        if (n >= 2 && p[0] == '0')
            return false;
        if (n >= 4)
            return false;
        return stoi(p, nullptr, 10) <= 255;
        
  }
  
    
    void solve(string s , int i, int part, vector<string>&ans,string res)
    {
        
        if(i==s.length() || part==4)
        {
            
            if(i==s.length() and part==4)
            {
                res.pop_back();
                ans.push_back(res);
            }
            
            
            return;
        }
        
        
         if(i+1<=s.length() and isvalid(s.substr(i,1)))
        {
           solve(s,i+1,part+1,ans,res+s.substr(i,1)+".");
        }
        
        
        if(i+2<=s.length() and isvalid(s.substr(i,2)))
        {
            solve(s,i+2,part+1,ans,res+s.substr(i,2)+".");
        }
        
        
        if(i+3<=s.length() and isvalid(s.substr(i,3)))
        {
            solve(s,i+3,part+1,ans,res+s.substr(i,3)+".");
        }
        
        
        
    }
    
    
    vector<string> restoreIpAddresses(string s) {
        
     vector<string>ans;
        
        solve(s,0,0,ans,"");
        return ans;
        
        
        
        
    }
};

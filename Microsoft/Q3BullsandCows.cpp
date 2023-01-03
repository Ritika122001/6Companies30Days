// 299. Bulls and Cows
// You are playing the Bulls and Cows game with your friend.
// You write down a secret number and ask your friend to guess what the number is. When your friend makes a guess, you provide a hint with the following info:
// The number of "bulls", which are digits in the guess that are in the correct position.
// The number of "cows", which are digits in the guess that are in your secret number but are located in the wrong position. Specifically, the non-bull digits in the guess that could be rearranged such that they become bulls.
// Given the secret number secret and your friend's guess guess, return the hint for your friend's guess.
// The hint should be formatted as "xAyB", where x is the number of bulls and y is the number of cows. Note that both secret and guess may contain duplicate digits.

// Example 1:

// Input: secret = "1807", guess = "7810"
// Output: "1A3B"
// Explanation: Bulls are connected with a '|' and cows are underlined:
// "1807"
//   |
// "7810"
// Example 2:

// Input: secret = "1123", guess = "0111"
// Output: "1A1B"


class Solution {
public:
    string getHint(string secret, string guess) 
    {
        unordered_map<int,int>mp1;
        unordered_map<int,int>mp2; 
        int bull=0;
        for(int i=0;i<guess.length();i++)
        {
            
            if(secret[i]==guess[i]) //if the same number is present at same index
            {
                bull++; 
            }
            else{
                mp1[guess[i]]++;
                mp2[secret[i]]++;
            }
            
        }
       int cow = 0;
       for(auto c : mp1)
       {
           if(mp2.find(c.first) != mp2.end()) cow+= min(c.second, mp2[c.first]); 
           
      }

          return to_string(bull) + "A" + to_string(cow) + "B";

        
    }
};
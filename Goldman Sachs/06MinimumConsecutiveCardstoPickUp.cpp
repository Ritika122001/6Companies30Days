// 2260. Minimum Consecutive Cards to Pick Up
// You are given an integer array cards where cards[i] represents the value of the ith card. A pair of cards are matching if the cards have the same value.

// Return the minimum number of consecutive cards you have to pick up to have a pair of matching cards among the picked cards. If it is impossible to have matching cards, return -1.

// Example 1:

// Input: cards = [3,4,2,3,4,7]
// Output: 4
// Explanation: We can pick up the cards [3,4,2,3] which contain a matching pair of cards with value 3. Note that picking up the cards [4,2,3,4] is also optimal.
// Example 2:

// Input: cards = [1,0,5,3]
// Output: -1
// Explanation: There is no way to pick up a set of consecutive cards that contain a pair of matching cards.


class Solution {
public:
    int minimumCardPickup(vector<int>& cards) {
        int ans = 10e5+10;
        int n = cards.size();
        unordered_map<int,pair<int,int>> mp; 
        for(int i=0;i<n;i++){
            int lcnt = mp[cards[i]].first;
            int lidx = mp[cards[i]].second;

            mp[cards[i]].first += 1;
            mp[cards[i]].second = i;
            
            if(mp[cards[i]].first > lcnt && lcnt != 0){
                int curr = i - lidx + 1;
                ans = min(curr,ans);
            }
        }
        if(ans == 10e5+10) return -1;
        return ans;
    }
};

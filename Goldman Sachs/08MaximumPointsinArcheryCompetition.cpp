// 2212. Maximum Points in an Archery Competition
// Alice and Bob are opponents in an archery competition. The competition has set the following rules:

// Alice first shoots numArrows arrows and then Bob shoots numArrows arrows.
// The points are then calculated as follows:
// The target has integer scoring sections ranging from 0 to 11 inclusive.
// For each section of the target with score k (in between 0 to 11), say Alice and Bob have shot ak and bk arrows on that section respectively. If ak >= bk, then Alice takes k points. If ak < bk, then Bob takes k points.
// However, if ak == bk == 0, then nobody takes k points.
// For example, if Alice and Bob both shot 2 arrows on the section with score 11, then Alice takes 11 points. On the other hand, if Alice shot 0 arrows on the section with score 11 and Bob shot 2 arrows on that same section, then Bob takes 11 points.
// You are given the integer numArrows and an integer array aliceArrows of size 12, which represents the number of arrows Alice shot on each scoring section from 0 to 11. Now, Bob wants to maximize the total number of points he can obtain.

// Return the array bobArrows which represents the number of arrows Bob shot on each scoring section from 0 to 11. The sum of the values in bobArrows should equal numArrows.

// If there are multiple ways for Bob to earn the maximum total points, return any one of them.

// Example 1:


// Input: numArrows = 9, aliceArrows = [1,1,0,1,0,0,2,1,0,1,2,0]
// Output: [0,0,0,0,1,1,0,0,1,2,3,1]
// Explanation: The table above shows how the competition is scored. 
// Bob earns a total point of 4 + 5 + 8 + 9 + 10 + 11 = 47.
// It can be shown that Bob cannot obtain a score higher than 47 points.
// Example 2:


// Input: numArrows = 3, aliceArrows = [0,0,1,0,0,0,0,0,0,0,0,2]
// Output: [0,0,0,0,0,0,0,0,1,1,1,0]
// Explanation: The table above shows how the competition is scored.
// Bob earns a total point of 8 + 9 + 10 = 27.
// It can be shown that Bob cannot obtain a score higher than 27 points.

class Solution {
    vector<int> bobArrows;
    int maxScore = 0;
    
    void solve(vector<int>& aliceArrows, vector<int>& arrows, int numArrows, int score, int ind, int n) {
        if(ind == n) {
            if(score > maxScore) {
                bobArrows = arrows;
                bobArrows[0] += numArrows;
                maxScore = score;
            }
            return;
        }
        
    
        arrows.push_back(0);
        solve(aliceArrows, arrows, numArrows, score, ind+1, n);
        arrows.pop_back();
        
        if(aliceArrows[ind] + 1 <= numArrows) {
            arrows.push_back(aliceArrows[ind] + 1);
            solve(aliceArrows, arrows, numArrows - aliceArrows[ind] - 1, score + ind, ind+1, n);
            arrows.pop_back();   
        }
    }
public:
    vector<int> maximumBobPoints(int numArrows, vector<int>& aliceArrows) {
        int n = aliceArrows.size();
        vector<int> arrows;
        solve(aliceArrows, arrows, numArrows, 0, 0, n);
        return bobArrows;
    }
};

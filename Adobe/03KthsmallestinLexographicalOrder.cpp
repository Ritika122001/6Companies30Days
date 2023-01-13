// 440. K-th Smallest in Lexicographical Order
// Given two integers n and k, return the kth lexicographically smallest integer in the range [1, n].
// Example 1:

// Input: n = 13, k = 2
// Output: 10
// Explanation: The lexicographical order is [1, 10, 11, 12, 13, 2, 3, 4, 5, 6, 7, 8, 9], so the second smallest number is 10.
// Example 2:

// Input: n = 1, k = 1
// Output: 1

class Solution {
public:
    int get(int prefix, int n) {
        long long p = 1;
        auto S = to_string(n), T = to_string(prefix);
        int dt = S.size() - T.size();
        int ans = 0;
        for(int i=0; i<dt; i++) {
            ans += p;
            p *= 10;
        }
        S = S.substr(0, T.size());
        if(S > T) {
            ans += p;
        } else if(S == T) {
            ans += n - prefix*p + 1;
        }
        return ans;
    }
    int findKthNumber(int n, int k) {
        int prefix = 1;
        while(k > 1) {
            int cnt = get(prefix, n);
            if(cnt < k) {
                k -= cnt;
                prefix++;
            } else {
                k --;
                prefix *= 10;
            }
        }
        return prefix;
    }
};

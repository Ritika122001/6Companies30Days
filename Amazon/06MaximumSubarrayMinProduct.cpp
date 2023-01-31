// 1856. Maximum Subarray Min-Product
// The min-product of an array is equal to the minimum value in the array multiplied by the array's sum.

// For example, the array [3,2,5] (minimum value is 2) has a min-product of 2 * (3+2+5) = 2 * 10 = 20.
// Given an array of integers nums, return the maximum min-product of any non-empty subarray of nums. Since the answer may be large, return it modulo 109 + 7.
// Note that the min-product should be maximized before performing the modulo operation. Testcases are generated such that the maximum min-product without modulo will fit in a 64-bit signed integer.
// A subarray is a contiguous part of an array.
// Example 1:
// Input: nums = [1,2,3,2]
// Output: 14
// Explanation: The maximum min-product is achieved with the subarray [2,3,2] (minimum value is 2).
// 2 * (2+3+2) = 2 * 7 = 14.
// Example 2:

// Input: nums = [2,3,3,1,2]
// Output: 18
// Explanation: The maximum min-product is achieved with the subarray [3,3] (minimum value is 3).
// 3 * (3+3) = 3 * 6 = 18.

class Solution {
public:
int maxSumMinProduct(vector<int>& nums) {
        int n = nums.size();
        int left[n], right[n];
        long long int sum[n];
        sum[0] = nums[0];
        for(int i=1;i<n;i++){
            sum[i] = sum[i-1]+nums[i];
        }
        stack<pair<int, int> > s1, s2;
        for (int i = 0; i < n; ++i) {
            int cnt = 1;
            while (!s1.empty() && (s1.top().first) > nums[i]) {
                cnt += s1.top().second;
                s1.pop();
            }
            s1.push({ nums[i], cnt });
            left[i] = cnt;
        }
        for (int i = n - 1; i >= 0; --i) {
            int cnt = 1;
            while (!s2.empty() && (s2.top().first) >= nums[i]) {
                cnt += s2.top().second;
                s2.pop();
            }

            s2.push({ nums[i], cnt });
            right[i] = cnt;
        }
        long long int res =0;
        for(int i=0;i<n;i++){
            int a = i-left[i]+1;
            int b = i+right[i]-1;
            long long int sumarr;
            if(a>0)
                sumarr = sum[b]-sum[a-1];
            else
                sumarr = sum[b];
            res = max(res, sumarr*nums[i]);
        }
        return res%1000000007;
    }
};

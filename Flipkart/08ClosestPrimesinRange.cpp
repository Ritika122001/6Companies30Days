// 2523. Closest Prime Numbers in Range
// Given two positive integers left and right, find the two integers num1 and num2 such that:

// left <= nums1 < nums2 <= right .
// nums1 and nums2 are both prime numbers.
// nums2 - nums1 is the minimum amongst all other pairs satisfying the above conditions.
// Return the positive integer array ans = [nums1, nums2]. If there are multiple pairs satisfying these conditions, return the one with the minimum nums1 value or [-1, -1] if such numbers do not exist.

// A number greater than 1 is called prime if it is only divisible by 1 and itself.
// Example 1:
// Input: left = 10, right = 19
// Output: [11,13]
// Explanation: The prime numbers between 10 and 19 are 11, 13, 17, and 19.
// The closest gap between any pair is 2, which can be achieved by [11,13] or [17,19].
// Since 11 is smaller than 17, we return the first pair.
// Example 2:

// Input: left = 4, right = 6
// Output: [-1,-1]
// Explanation: There exists only one prime number in the given range, so the conditions cannot be satisfied.

class Solution {
	public:
		vector<int> closestPrimes(int left, int right) {

			vector<bool> p(1e6+1,true);
			p[0]=p[1]=false;
			for(int i=2;i*i<=1e6;i++){
				for(int j=2;i*j<=1e6;j++) p[i*j]=false;
			}

			vector<int> ans;
			vector<int> temp;
			int diff=1e9;
			for(int i=left;i<=right;i++){
				if(p[i]){
					temp.push_back(i);
					if(temp.size()==2){
						if(temp[1]-temp[0]<diff){
							diff=temp[1]-temp[0];
							ans=temp;
						}
						temp.clear();
						temp.push_back(i);
					}
				}    
			}
			if(ans.size()==0) return {-1,-1};
			return ans;
		}
	};

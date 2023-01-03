// 2426. Number of Pairs Satisfying Inequality
// You are given two 0-indexed integer arrays nums1 and nums2, each of size n, and an integer diff. Find the number of pairs (i, j) such that:

// 0 <= i < j <= n - 1 and
// nums1[i] - nums1[j] <= nums2[i] - nums2[j] + diff.
// Return the number of pairs that satisfy the conditions.

// Example 1:

// Input: nums1 = [3,2,5], nums2 = [2,2,1], diff = 1
// Output: 3
// Explanation:
// There are 3 pairs that satisfy the conditions:
// 1. i = 0, j = 1: 3 - 2 <= 2 - 2 + 1. Since i < j and 1 <= 1, this pair satisfies the conditions.
// 2. i = 0, j = 2: 3 - 5 <= 2 - 1 + 1. Since i < j and -2 <= 2, this pair satisfies the conditions.
// 3. i = 1, j = 2: 2 - 5 <= 2 - 1 + 1. Since i < j and -3 <= 2, this pair satisfies the conditions.
// Therefore, we return 3.


class Solution 
{
public:

    long long int cnt;
   
    void solve(vector<int>& nums, int start, int mid, int end,int d)
    {
        
        int l = start, r = mid + 1;
        while(l <= mid && r <= end)
        {
            if(nums[l]<=(nums[r]+d))   
            {
                cnt += (end - r+1);
                l++;
            }
            else  //move r close to l
            {
                r++;
            }
        }
   
        sort(nums.begin() + start, nums.begin() + end + 1); 
        return;
         
    }
    void mergeSort(vector<int>& nums, int start, int end,int d)
    {
        if(start == end) 
            return;
         //merge sort algo
        int mid = (start + end)/2;
        mergeSort(nums,start, mid,d);
        mergeSort(nums,mid+1,end,d);
        
        solve(nums,start,mid,end,d);
        return;
        
    }
    long long numberOfPairs(vector<int>& a, vector<int>& b, int d) 
    {
        int n = a.size();
        vector<int>vec(n);  
        
        cnt = 0;
        for(int i=0;i<n;i++)
        vec[i]=a[i]-b[i];               
			
        mergeSort(vec,0,n-1,d);
		
        return cnt;
    }
};
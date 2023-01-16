// 698. Partition to K Equal Sum Subsets
// Given an integer array nums and an integer k, return true if it is possible to divide this array into k non-empty subsets whose sums are all equal.

// Example 1:

// Input: nums = [4,3,2,3,5,2,1], k = 4
// Output: true
// Explanation: It is possible to divide it into 4 subsets (5), (1, 4), (2,3), (2,3) with equal sums.
// Example 2:

// Input: nums = [1,2,3,4], k = 3
// Output: false

class Solution {
public:
    

    bool subset(vector<int>&nums ,int bucketsum , int k , int target , int i , vector<int>&vis, vector<int>&memo)
    {

        int n = nums.size();
        if(k == 1)
            return true;
        
        if(i == n)
            return false;
        
        // we found one subset with sum == target, find other k - 1  subsets with sum == target
        
        if(bucketsum == target)
        {
            return subset(nums, 0, k - 1, target, 0,vis,memo);
        }

        for(int j=i;j<n;j++)
        {
            if(vis[j]==0 && bucketsum+nums[j]<=target)
            {
                vis[j]=1;
                bucketsum+=nums[j];

                if(subset(nums,bucketsum,k,target,j+1,vis,memo))
                {
                    return memo[i] = true;
                }

               vis[j] =0;
               bucketsum-=nums[j];
    
     }
        }

     return memo[i] = false;
        }


      
    bool canPartitionKSubsets(vector<int>& nums, int k) {

        int sum=0;
     vector<int>vis(nums.size(),0);

        vector<int>memo(nums.size(),-1);
        for(int i=0;i<nums.size();i++)
        {
            sum+=nums[i];
        }
        
        
         if(sum%k!=0)
                return false;
        
        return subset(nums,0,k,sum/k,0,vis,memo);
         
    }
};

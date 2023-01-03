// 581. Shortest Unsorted Continuous Subarray
// Given an integer array nums, you need to find one continuous subarray that if you only sort this subarray in ascending order, then the whole array will be sorted in ascending order.

// Return the shortest such subarray and output its length.
// Example 1:

// Input: nums = [2,6,4,8,10,9,15]
// Output: 5
// Explanation: You need to sort [6, 4, 8, 10, 9] in ascending order to make the whole array sorted in ascending order.
// Example 2:

// Input: nums = [1,2,3,4]
// Output: 0
// Example 3:

// Input: nums = [1]
// Output: 0


class Solution {
public:
  int findUnsortedSubarray(vector<int>& nums) {
      

      int range_min = INT_MAX, range_max = INT_MIN;
      int st=-1;
      int en=-1;
      int ans=0;
      
      for(int i=0;i<nums.size()-1;i++)
      {
    
        if(nums[i] > nums[i+1])
        {
          
          if(st==-1)
          {
              st=i;       
          
          }
          
            en=i+1;
            range_min = min(range_min, nums[i+1]);
            range_max = max(range_max,nums[i]);
          
        }
            
      }
      
      
      if(range_min==INT_MAX and range_max==INT_MIN)
      {
        return 0;
      }
      
      
      for(int i=0;i<st;i++)
      {
        if(nums[i]>range_min)
        {
          st=i; //find starting index
          break;
        }
      }
      
      
      for(int i=nums.size()-1;i>en;i--)
      {
        if(nums[i] < range_max)
        {
          en=i; //find ending index
          break; 
        }
      }
      
      
      return en-st+1; //return length
       
    }
};
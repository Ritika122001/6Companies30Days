//1305. All Elements in Two Binary Search Trees
// Companies
// Given two binary search trees root1 and root2, return a list containing all the integers from both trees sorted in ascending order.

// Example 1:
// Input: root1 = [2,1,4], root2 = [1,0,3]
// Output: [0,1,1,2,3,4]
// Example 2:

// Input: root1 = [1,null,8], root2 = [8,1]
// Output: [1,1,8,8]

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Solution {
  
public:
  
  void inorder1(TreeNode* root1, vector<int>&ans1)
  {
    if(root1==NULL)
    {
      return;
      
    }
    
    inorder1(root1->left,ans1);
    ans1.push_back(root1->val);
    inorder1(root1->right,ans1);
    
    
  }
  
    void inorder2(TreeNode* root2, vector<int>&ans2)
  {
    if(root2==NULL)
    {
      return;
      
    }
    
    inorder2(root2->left,ans2);
    ans2.push_back(root2->val);
    inorder2(root2->right,ans2);
    
    
  }
  
  vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {
   
      vector<int>ans1;
      vector<int>ans2;
      inorder1(root1,ans1);
      inorder2(root2,ans2);
      vector<int>res(ans1.size() + ans2.size());
      int i=0;
      int j=0;
      int k=0;
      
      while(i<ans1.size() and j<ans2.size())
      {
        if(ans1[i] <= ans2[j])
      {
         res[k]=ans1[i];
          k++;
          i++;
      }
        
        else 
        {
          res[k]=ans2[j];
          k++;
          j++;
          
        }
        
      }
     
      while(i<ans1.size())
      {
        res[k]=ans1[i];
        k++;
        i++;
      }
             
      while(j<ans2.size())
      {
        res[k]=ans2[j];
        k++;
        j++;
      }
      
      return res; 
    }
};

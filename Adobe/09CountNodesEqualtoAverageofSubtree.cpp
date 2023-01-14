// 2265. Count Nodes Equal to Average of Subtree
// Given the root of a binary tree, return the number of nodes where the value of the node is equal to the average of the values in its subtree.

// Note:

// The average of n elements is the sum of the n elements divided by n and rounded down to the nearest integer.
// A subtree of root is a tree consisting of root and all of its descendants.
 

// Example 1:


// Input: root = [4,8,5,0,1,null,6]
// Output: 5
// Explanation: 
// For the node with value 4: The average of its subtree is (4 + 8 + 5 + 0 + 1 + 6) / 6 = 24 / 6 = 4.
// For the node with value 5: The average of its subtree is (5 + 6) / 2 = 11 / 2 = 5.
// For the node with value 0: The average of its subtree is 0 / 1 = 0.
// For the node with value 1: The average of its subtree is 1 / 1 = 1.
// For the node with value 6: The average of its subtree is 6 / 1 = 6.
// Example 2:

// Input: root = [1]
// Output: 1
// Explanation: For the node with value 1: The average of its subtree is 1 / 1 = 1.


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
  int sum=0;
    int cnt=0;
     int res;
 int avg(TreeNode* root)
 {

    if(root==NULL) return 0;

    sum+=root->val;
    cnt++;
    avg(root->left);
    avg(root->right);
    return (sum);


 }


 void solve(TreeNode* root)
 {

  
  if(root==NULL) return ;
  int k = avg(root);

  if(cnt>0 && (k/cnt)==root->val)
  {
      res++;

  }

  sum=0;
  cnt=0;

  solve(root->left);
  solve(root->right);


 }

    int averageOfSubtree(TreeNode* root) {

        solve(root);
        return res;
        
    }
};

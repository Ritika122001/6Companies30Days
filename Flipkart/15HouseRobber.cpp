// 337. House Robber III
// The thief has found himself a new place for his thievery again. There is only one entrance to this area, called root.

// Besides the root, each house has one and only one parent house. After a tour, the smart thief realized that all houses in this place form a binary tree. It will automatically contact the police if two directly-linked houses were broken into on the same night.

// Given the root of the binary tree, return the maximum amount of money the thief can rob without alerting the police.
// Example 1:
// Input: root = [3,2,3,null,3,null,1]
// Output: 7
// Explanation: Maximum amount of money the thief can rob = 3 + 3 + 1 = 7.
// Example 2:

// Input: root = [3,4,5,1,3,null,1]
// Output: 9
// Explanation: Maximum amount of money the thief can rob = 4 + 5 = 9.

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
private:
    unordered_map<TreeNode*,int>memo;
    int helper(TreeNode* root) {
        if (root == NULL) return 0;
        
        if (memo.count(root)){
            return memo[root];
        } 
    
        int ans_including_root = root->val;
    
        if (root->left != NULL) {
              ans_including_root += helper(root->left->left) + helper(root->left->right);
        }
    
        if (root->right != NULL) {
              ans_including_root += helper(root->right->left) + helper(root->right->right);
        }
        
        int ans_excluding_root = helper(root->left) + helper(root->right);
    
        int ans = max(ans_including_root , ans_excluding_root);
        
        memo[root]=ans;
    
        return ans;
   }
    
public:
    int rob(TreeNode* root) {
        return helper(root);
    }    
};

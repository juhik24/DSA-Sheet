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
    // Time = O(n), Space = O(n)->recursion stack
    
    bool solve(TreeNode* root, int targetSum, int sum) {
        if(root == NULL) return false;
        sum += root->val;
        if(sum == targetSum && root->left == NULL && root->right == NULL) return true;
        return solve(root->left, targetSum, sum) || solve(root->right, targetSum, sum);
    }
    
    bool hasPathSum(TreeNode* root, int targetSum) {
        int sum = 0;
        if(root == NULL) return false;
        return solve(root, targetSum, sum);
    }
};
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
    
    // In optimized approach, we'll calculate the height in the same dfs recursion
    int height(TreeNode* root, bool &ans) {
        if(root == NULL) return 0;
        int left = height(root->left, ans);
        int right = height(root->right, ans);
        if(ans == false) return false;
        if(abs(left-right) > 1) ans = false;
        return max(left, right)+1;
    }
    
    bool isBalanced(TreeNode* root) {
        bool ans = true;
        if(root == NULL) return true;
        height(root, ans);
        return ans;
    }
};

// Brute force = O(n^2), Space = O(n)->recursion stack

// Here we'll calculate height of left subtree and right subtree for every node and check if its difference is less than or equal to 1. 
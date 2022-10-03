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
    
    // We'll traverse the tree in inorder and maintain a prev pointer and calculate the difference between two prev node and current node and update the diff when we get a minimum absolute diff.
    
    void solve(TreeNode* root, int &diff, TreeNode* &prev) {
        if(root->left) solve(root->left, diff, prev);
        if(prev != NULL) {
            diff = min(diff, abs(root->val-prev->val));
        }
        prev = root;
        if(root->right) solve(root->right, diff, prev);
    }
    
    int getMinimumDifference(TreeNode* root) {
        int diff = INT_MAX;
        TreeNode* prev = NULL;
        solve(root, diff, prev);
        return diff;
    }
};
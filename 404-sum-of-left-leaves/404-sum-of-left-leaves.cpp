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
    int sum = 0;
    void solve(TreeNode* root, bool flag) {
        if(root == NULL) return;
        if(root->left == NULL && root->right == NULL) {
            if(flag == true) {
                sum += root->val;
            }
            return;
        }
        solve(root->left, true);
        solve(root->right, false);
    }
    
    int sumOfLeftLeaves(TreeNode* root) {
        if(root->left == NULL && root->right == NULL) return sum;
        if(root->left) solve(root->left, true);
        if(root->right) solve(root->right, false);
        return sum;
    }
};
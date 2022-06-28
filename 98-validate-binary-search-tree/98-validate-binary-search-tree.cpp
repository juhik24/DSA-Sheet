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
    bool check(TreeNode* root, long mn, long mx) {
        if(root == NULL) return true;
        if(root->val > mn && root->val < mx) {
            return check(root->left, mn, root->val) && check(root->right, root->val, mx);
        }
        else return false;
    }
    
    bool isValidBST(TreeNode* root) {
        if(root->left == NULL && root->right == NULL) return true;
        return check(root, LONG_MIN, LONG_MAX);
    }
};
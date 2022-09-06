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
    // Time = O(n), Space = O(n) for recursion stack
    
    bool hasOne(TreeNode* root) {
        if(root == NULL) return false;
        bool left = hasOne(root->left);
        bool right = hasOne(root->right);
        if(!left) root->left = NULL;
        if(!right) root->right = NULL;
        if(root->val == 1 || left == true || right == true) return true;
        else return false;
    }
    
    TreeNode* pruneTree(TreeNode* root) {
        if(hasOne(root)) return root;
        else return NULL;
    }
};
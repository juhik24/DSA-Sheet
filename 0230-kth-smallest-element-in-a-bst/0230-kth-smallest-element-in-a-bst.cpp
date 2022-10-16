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
    
    void solve(TreeNode* root, int &k, int &data) {
        if(root == NULL) return;
        solve(root->left, k, data);
        if(k == 1) {
            data = root->val;
        }
        k--;
        solve(root->right, k, data);
    }
    
    int kthSmallest(TreeNode* root, int k) {
        int data = 0;
        solve(root, k, data);
        return data;
    }
};
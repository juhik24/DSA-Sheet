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
    // Time = O(n), Space = O(n) 
    
    void solve(TreeNode* root, int &sum, bool flag) {
        if(root == NULL) return;
        if(root->left == NULL && root->right == NULL) {
            if(flag == true) {
                sum += root->val;
            }
            return;
        }
        solve(root->left, sum, true);
        solve(root->right, sum, false);
    }
    
    int sumOfLeftLeaves(TreeNode* root) {
        int sum = 0;
        if(root->left == NULL && root->right == NULL) return sum;
        solve(root->left, sum, true);
        solve(root->right, sum, false);
        return sum;
    }
};
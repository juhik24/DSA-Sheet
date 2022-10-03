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
    
    // Here we'll maintain a bool flag which will be true for left side and false for right side.
    // and traverse the tree in preorder and check if it is a leaf node (that is left child is NULL & right child is NULL) and flag is true then it is left leaf and we'll add its value to the sum
    
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
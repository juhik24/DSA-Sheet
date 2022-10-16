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
    
    void inorder(TreeNode* root, int &k, int &data) {
        if(root == NULL) return;
        inorder(root->left, k, data);
        if(k==1) data = root->val;
        k--;
        inorder(root->right, k, data);
    }
    
    int kthSmallest(TreeNode* root, int k) {
        int data = 0;
        inorder(root, k, data);
        return data;
    }
};
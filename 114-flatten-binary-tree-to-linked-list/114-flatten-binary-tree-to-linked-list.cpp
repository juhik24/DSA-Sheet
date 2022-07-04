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
    void preorder(TreeNode* root, queue<TreeNode*>&q) {
        if(root == NULL) return;
        q.push(root);
        preorder(root->left, q);
        preorder(root->right, q);
    }
    
    void flatten(TreeNode* root) {
        if(root == NULL) return;
        queue<TreeNode*>q;
        preorder(root, q);
        q.pop();
        TreeNode* temp = root;
        while(!q.empty()) {
            temp->right = q.front();
            temp->left = NULL;
            temp = q.front();
            q.pop();
        }
    }
};
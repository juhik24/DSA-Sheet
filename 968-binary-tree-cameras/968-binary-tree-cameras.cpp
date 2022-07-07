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
    int cam = 0;
    unordered_set<TreeNode*>s;
    
    void solve(TreeNode* root, TreeNode* parent) {
        if(root != NULL) {
            solve(root->left, root);
            solve(root->right, root);
            if(parent == NULL && s.find(root) == s.end() || s.find(root->left) == s.end() || s.find(root->right) == s.end()) {
                cam++;
                s.insert(root);
                s.insert(parent);
                s.insert(root->left);
                s.insert(root->right);
            }
        }
    }
    
    int minCameraCover(TreeNode* root) {
        if(root == NULL) return cam;
        s.insert(NULL);
        solve(root, NULL);
        return cam;
    }
};
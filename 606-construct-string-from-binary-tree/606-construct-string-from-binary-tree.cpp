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
    string tree_to_string(TreeNode* root, string &ans) {
        if(root == NULL) return ans;
        ans += to_string(root->val);
        if(root->left) {
            ans.push_back('(');
            tree_to_string(root->left, ans);
            ans.push_back(')');
        }
        if(root->left && root->right) {
            ans.push_back('(');
            tree_to_string(root->right, ans);
            ans.push_back(')');
        }
        else if(root->right && root->left == NULL) {
            ans += "()(";
            tree_to_string(root->right, ans);
            ans.push_back(')');
        }
        return ans;
    }
    
    string tree2str(TreeNode* root) {
        string ans = "";
        return tree_to_string(root, ans);
        
    }
};
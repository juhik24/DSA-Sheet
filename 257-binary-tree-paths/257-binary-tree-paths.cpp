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
    void paths(TreeNode* root, string str, vector<string>&ans) {
        string temp = str;
        temp += "->" + to_string(root->val);
        if(root->left == NULL && root->right == NULL) {
            ans.push_back(temp);
            return;
        }
        if(root->left) paths(root->left, temp, ans);
        if(root->right) paths(root->right, temp, ans);
    }
    
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string>ans;
        string str = "";
        if(root == NULL) return ans;
        str += to_string(root->val);
        if(root->left == NULL && root->right == NULL) {
            ans.push_back(str);
            return ans;
        }
        if(root->left) paths(root->left, str, ans);
        if(root->right) paths(root->right, str, ans);
        return ans;
    }
};
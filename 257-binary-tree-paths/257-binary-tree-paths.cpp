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
    void paths(TreeNode* root, vector<string>&ans, string &str) {
        if(root->left == NULL && root->right == NULL) {
            string temp = str;
            temp = temp + "->" + to_string(root->val);
            ans.push_back(temp);
            return;
        }
        
        string ch = to_string(root->val);
        string temp = str;
        temp =  temp + "->" + ch;
        if(root->left) paths(root->left, ans, temp);
        if(root->right) paths(root->right, ans, temp);
    }
    
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string>ans;
        string str = "";
        if(root == NULL) {
            ans.push_back(str);
            return ans;
        }
        string s = to_string(root->val);
        str += s;
        if(root->left == NULL && root->right == NULL) {
            ans.push_back(str);
            return ans;
        }
        if(root->left) paths(root->left, ans, str);
        if(root->right) paths(root->right, ans, str);
        return ans;
    }
};
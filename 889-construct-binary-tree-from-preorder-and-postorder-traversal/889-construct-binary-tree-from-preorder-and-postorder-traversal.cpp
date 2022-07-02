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
    unordered_map<int, int>mp;
    TreeNode* constructFromPrePost(vector<int>& preorder, vector<int>& postorder) {
        for(int i = 0; i < postorder.size(); i++) {
            mp[postorder[i]] = i;
        }
        return solve(preorder, 0, preorder.size()-1, postorder, 0, postorder.size()-1);
    }
    
    TreeNode* solve(vector<int>&preorder, int preStart, int preEnd, vector<int>&postorder, int postStart, int postEnd) {
        if(preStart > preEnd) {
            return NULL;
        }
        TreeNode* root = new TreeNode(preorder[preStart]);
        if(preStart == preEnd) return root;
        
        int postIndex = mp[preorder[preStart+1]];
        
        int len = postIndex - postStart + 1;
        root->left = solve(preorder, preStart+1, preStart+len, postorder, postStart, postIndex);
        root->right = solve(preorder, preStart+len+1, preEnd, postorder, postIndex+1, postEnd-1);
        return root;
    }
};
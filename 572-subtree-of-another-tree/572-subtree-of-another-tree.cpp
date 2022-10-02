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
    #include<bits/stdc++.h>
    void inorder(TreeNode* root, string &s) {
        if(root == NULL) {
            s += '$';
            return;
        }
        inorder(root->left, s);
        s += to_string(root->val);
        inorder(root->right, s);
    }
    
    void preorder(TreeNode* root, string &s) {
        if(root == NULL) {
            s += '$';
            return;
        }
        s += to_string(root->val);
        preorder(root->left, s);
        preorder(root->right, s);
    }
    
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if(subRoot == NULL) return true;
        if(root == NULL) return false;
        string inT = "", inS = "";
        inorder(root, inT);
        inorder(subRoot, inS);
        //if inS is not a substring of inT, return false;
        if(inT.find(inS) == string::npos) return false;
        string preS = "", preT = "";
        preorder(root, preT);
        preorder(subRoot, preS);
        if(preT.find(preS) == string::npos) return false;
        return true;
    }
};
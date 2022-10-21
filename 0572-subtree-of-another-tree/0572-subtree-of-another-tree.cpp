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
    // Time = O(nm), Space = O(n+m) 
    
    bool sameTree(TreeNode* root, TreeNode* subRoot) {
        if(root == NULL && subRoot == NULL) return true;
        if(root != NULL && subRoot != NULL && root->val == subRoot->val) {
            return sameTree(root->left, subRoot->left) && sameTree(root->right, subRoot->right);
        }
        return false;
    }
    
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if(subRoot == NULL) return true;
        if(root == NULL) return false;
        if(sameTree(root, subRoot)) return true;
        return (isSubtree(root->left, subRoot) || isSubtree(root->right, subRoot));
    }
};

// Optimized:

// Time = O(n),  Space = O(n);
    
    // Here we'll store inorder and preorder traversal of root tree and subRoot tree in  strings.
    // Then if both inorder & preorder traversal of subRoot is a substring of inorder & preorder traversal of root then subRoot is a subtree of the main tree.
    
//     #include<bits/stdc++.h>
//     void inorder(TreeNode* root, string &s) {
//         if(root == NULL) {
//             s += '$';
//             return;
//         }
//         inorder(root->left, s);
//         s += to_string(root->val);
//         inorder(root->right, s);
//     }
    
//     void preorder(TreeNode* root, string &s) {
//         if(root == NULL) {
//             s += '$';
//             return;
//         }
//         s += to_string(root->val);
//         preorder(root->left, s);
//         preorder(root->right, s);
//     }
    
//     bool isSubtree(TreeNode* root, TreeNode* subRoot) {
//         if(subRoot == NULL) return true;
//         if(root == NULL) return false;
//         string inT = "", inS = "";
//         inorder(root, inT);
//         inorder(subRoot, inS);
//         //if inS is not a substring of inT, return false;
//         if(inT.find(inS) == string::npos) return false;
//         string preS = "", preT = "";
//         preorder(root, preT);
//         preorder(subRoot, preS);
//         if(preT.find(preS) == string::npos) return false;
//         return true;
//     }
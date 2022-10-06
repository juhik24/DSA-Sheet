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
    
    // Here also we'll do inorder traversal and keep a prev pointer if value of prev < curr node then we'll prev and curr node in first and second pointer and if again got prev < curr then we'll store curr in last pointer. And we'll swap (first, last). If we didn't get last then we'll swap(first , middle).
    
    TreeNode* prev, *first, *middle, *last;
    
    void inorder(TreeNode* root) {
        if(root == NULL) return;
        inorder(root->left);
        if(root->val < prev->val) {
            if(first == NULL) {
                first = prev;
                middle = root;
            }
            else last = root;
        }
        prev = root;
        inorder(root->right);
    }
    
    void recoverTree(TreeNode* root) {
        first = middle = last = NULL;
        prev = new TreeNode(INT_MIN);
        inorder(root);
        if(first && last) swap(first->val, last->val);
        else swap(first->val, middle->val);
    }
};

// Brute force = Time = O(n+nlogn), Space = O(n)->vector

// Here we'll store all node values in a vector and then sort it. as inorder of bst contains elements in sorted order. And then we can assign vector values to nodes . 

// void inorder(TreeNode* root, vector<int>&v) {
//         if(root == NULL) return;
//         inorder(root->left, v);
//         v.push_back(root->val);
//         inorder(root->right, v);
//     }
    
//     void solve(TreeNode* root, vector<int>&v, int &i) {
//         if(root == NULL) return;
//         solve(root->left, v, i);
//         if(root->val != v[i]) {
//             root->val = v[i];
//         }
//         i++;
//         solve(root->right, v, i);
//     }
    
//     void recoverTree(TreeNode* root) {
//         vector<int>v;
//         inorder(root, v);
//         sort(v.begin(), v.end());
//         int i = 0;
//         solve(root, v, i);
//     }
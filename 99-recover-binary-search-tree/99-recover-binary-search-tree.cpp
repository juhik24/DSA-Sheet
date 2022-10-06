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
    
    // Here also we'll do inorder traversal and keep three pointers first, middle & last. Whenever we get prev node value > cuurent node then first pointer will point to prev and middle will point to current node.
    // When we find again that prev > cuurent node then we'll update last pointer with the current node.
    //If the last pointer is NULL then we'll swap(first, middle) otherwise we'll swap(first, last)
    
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

// Brute force = Time = O(nlogn), Space = O(n)->vector

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
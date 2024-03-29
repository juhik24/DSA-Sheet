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
    
    // We can optimize the brute force by calculating height in the same recursion rather than calling a height function separately for every node.
    
    int solve(TreeNode* root, int &d) {
        if(root == NULL) return 0;
        int left = solve(root->left, d);
        int right = solve(root->right, d);
        d = max(d, left + right);
        return max(left, right)+1;
    }
    
    int diameterOfBinaryTree(TreeNode* root) {
        int d = 0;
        solve(root, d);
        return d;
    }
};

// Brute force: Time = O(n^2) as we'll calculate height for every node, Space = O(n)->for recursion stack

// For any given node, we'll find out the height of left half and right half and then we'll add them up.
    // so that is the longest path through the given node.
    // So if we find left height + right height across every given node, so max of left height and right height will be the diameter of the tree.
    // We have to find the left height & right height for every node.
    
//     int Height(TreeNode* root) {
//         if(root == NULL) return 0;
//         return max(Height(root->left), Height(root->right))+1;
//     }
    
//     void solve(TreeNode* root, int &d) {
//         if(root == NULL) return;
//         int left = Height(root->left);
//         int right = Height(root->right);
//         d = max(d, left+right);
//         solve(root->left, d);
//         solve(root->right, d);
//     }
    
//     int diameterOfBinaryTree(TreeNode* root) {
//         int d = 0;
//         solve(root, d);
//         return d;
//     }
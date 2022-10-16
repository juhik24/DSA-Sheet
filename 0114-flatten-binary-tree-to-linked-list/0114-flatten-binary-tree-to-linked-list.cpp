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
    // Time = O(n), Space = O(n) -> recursion stack
    
    // Here we can do a reverse postorder and maintain a prev pointer. After the reverse postorder gets completed for a node we'll assign the prev as right child of that node and store the current node in the prev.
    
    void solve(TreeNode* node, TreeNode* &prev) {
        if(node == NULL) return;
        solve(node->right, prev);
        solve(node->left, prev);
        node->right = prev;
        node->left = NULL;
        prev = node;
    }
    
    void flatten(TreeNode* root) {
        TreeNode* prev = NULL;
        solve(root, prev);
    }
};

// Time = O(n), Space = O(n)

// Here we can do a preorder traversal and store all the nodes in a queue and then we can change the pointers of right child by popping elements from queue.
    
//     void preorder(TreeNode* root, queue<TreeNode*>&q) {
//         if(root == NULL) return;
//         q.push(root);
//         preorder(root->left, q);
//         preorder(root->right, q);
//     }
    
//     void flatten(TreeNode* root) {
//         if(root == NULL) return;
//         queue<TreeNode*>q;
//         preorder(root, q);
//         TreeNode* temp = q.front();
//         q.pop();
//         while(!q.empty()) {
//             temp->right = q.front();
//             temp->left = NULL;
//             temp = q.front();
//             q.pop();
//         }
//     }
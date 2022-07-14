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
    int idx = 0;
    
    int findMid(vector<int>& inorder, int lb, int ub, int ele) {
        for(int i = lb; i <= ub; i++) {
            if(inorder[i] == ele)
                return i;
        }
        return 0;
    }
    
    TreeNode* solve(vector<int>&preorder, vector<int>& inorder, int lb, int ub) {
        if(lb > ub) return NULL;
        
        TreeNode* res = new TreeNode(preorder[idx++]);
        if(lb == ub) return res;
        
        int mid = findMid(inorder, lb, ub, res->val);
        res->left = solve(preorder, inorder, lb, mid-1);
        res->right = solve(preorder, inorder, mid+1, ub);
        return res;
    }
    
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int n = preorder.size();
        TreeNode* root = solve(preorder, inorder, 0, n-1);
        return root;
    }
};
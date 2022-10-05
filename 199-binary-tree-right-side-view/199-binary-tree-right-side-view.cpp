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
    // Time = O(n), Space = O(h)
    
    // In this we'll do reverse preorder (preorder = Root L R, reverse preorder = Root R L)
    // We'll maintain a level variable, if level == ans.size() then we'll push that in our ans vector.
    // As we are first going in right side so the first element on that level will be rightmost element.
    
    void solve(TreeNode* root, int level, vector<int> &ans) {
        if(root == NULL) return;
        if(level == ans.size()) {
            ans.push_back(root->val);
        }
        solve(root->right, level+1, ans);
        solve(root->left, level +1, ans);
    }
    
    vector<int> rightSideView(TreeNode* root) {
        vector<int>ans;
        if(root == NULL) return ans;
        solve(root, 0, ans);
        return ans;
    }
};

//Brute force: Time = O(n), Space = O(n)->Worst case(skew tree)

// We'll do level order traversal in this.
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
    void innerDFS(TreeNode* root, int targetSum, long long sum, int &cnt) {
        if(root == NULL) return;
        sum += root->val;
        if(sum == targetSum) cnt++;
        innerDFS(root->left, targetSum, sum, cnt);
        innerDFS(root->right, targetSum, sum, cnt);
    }
    
    void outerDFS(TreeNode* root, int targetSum, int &cnt) {
        if(root == NULL) return;
        long long sum = 0;
        innerDFS(root, targetSum, sum, cnt);
        outerDFS(root->left, targetSum, cnt);
        outerDFS(root->right, targetSum, cnt);
    }
    
    int pathSum(TreeNode* root, int targetSum) {
        int cnt = 0;
        if(root == NULL) return cnt;
        outerDFS(root, targetSum, cnt);
        return cnt;
    }
};
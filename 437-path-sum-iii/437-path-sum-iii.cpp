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
    // Time = O(n), Space = O(n)->vector
    
    void solve(TreeNode* root, int targetSum, vector<int>&path, int &cnt) {
        if(root == NULL) return;
        path.push_back(root->val);
        solve(root->left, targetSum, path, cnt);
        solve(root->right, targetSum, path, cnt);
        long long sum = 0;
        for(int i = path.size()-1; i >= 0; i--) {
            sum += path[i];
            if(sum == targetSum) cnt++;
        }
        path.pop_back();
    }
    
    int pathSum(TreeNode* root, int targetSum) {
        int cnt = 0;
        vector<int>paths;
        solve(root, targetSum, paths, cnt);
        return cnt;
    }
};

// Brute force = Time = O(n^2), Space = O(n)->recursion stack

// Here we'll be using an outer DFS for selecting each node and an inner DFS for calculating the sum and checking if we'll get our target Sum from that node.

// void innerDFS(TreeNode* root, int targetSum, long long sum, int &cnt) {
//         if(root == NULL) return;
//         sum += root->val;
//         if(sum == targetSum) cnt++;
//         innerDFS(root->left, targetSum, sum, cnt);
//         innerDFS(root->right, targetSum, sum, cnt);
//     }
    
//     void outerDFS(TreeNode* root, int targetSum, int &cnt) {
//         if(root == NULL) return;
//         long long sum = 0;
//         innerDFS(root, targetSum, sum, cnt);
//         outerDFS(root->left, targetSum, cnt);
//         outerDFS(root->right, targetSum, cnt);
//     }
    
//     int pathSum(TreeNode* root, int targetSum) {
//         int cnt = 0;
//         if(root == NULL) return cnt;
//         outerDFS(root, targetSum, cnt);
//         return cnt;
//     }
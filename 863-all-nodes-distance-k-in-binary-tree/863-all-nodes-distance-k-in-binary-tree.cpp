/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    void mark_parent(TreeNode* root, unordered_map<TreeNode*, TreeNode*>&parent) {
        queue<TreeNode*>q;
        q.push(root);
        while(!q.empty()) {
            TreeNode* cur = q.front();
            q.pop();
            if(cur->left) {
                q.push(cur->left);
                parent[cur->left] = cur;
            }
            if(cur->right) {
                q.push(cur->right);
                parent[cur->right] = cur;
            }
        }
    }
    
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        unordered_map<TreeNode*, TreeNode*>parent;
        mark_parent(root, parent);
        unordered_map<TreeNode*, bool>visited;
        queue<TreeNode*>q;
        q.push(target);
        visited[target] = true;
        int level = 0;
        while(!q.empty()) {
            int size = q.size();
            if(level == k) break;
            for(int i = 0; i < size; i++) {
                TreeNode* cur = q.front();
                q.pop();
                if(cur->left && visited.find(cur->left) == visited.end()) {
                    visited[cur->left] = true;
                    q.push(cur->left);
                }
                if(cur->right && visited.find(cur->right) == visited.end()) {
                    visited[cur->right] = true;
                    q.push(cur->right);
                }
                if(parent[cur] && !visited[parent[cur]]) {
                    visited[parent[cur]] = true;
                    q.push(parent[cur]);
                }
            }
            level++;
        }
        vector<int>ans;
        while(!q.empty()) {
            TreeNode* cur = q.front();
            q.pop();
            ans.push_back(cur->val);
        }
        return ans;
    }
};
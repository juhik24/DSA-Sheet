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
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        vector<vector<int>>ans;
        map<int, vector<int>>mp;
        queue<pair<int, TreeNode*>>q;
        q.push({0, root});
        while(!q.empty()) {
            multiset<pair<int, int>>s;
            int size = q.size();
            for(int i = 0; i < size; i++) {
                TreeNode* temp = q.front().second;
                int j = q.front().first;
                s.insert({j, temp->val});
                q.pop();
                if(temp->left) {
                    q.push({j-1, temp->left});
                }
                if(temp->right) {
                    q.push({j+1, temp->right});
                }
            }
            for(auto i : s) {
                mp[i.first].push_back(i.second);
            }
        }
        for(auto i : mp) {
            vector<int>v = i.second;
            ans.push_back(v);
        }
        return ans;
    }
};
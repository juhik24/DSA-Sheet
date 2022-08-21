/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:
#include<bits/stdc++.h>
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string ans = "";
        if(root == NULL) return ans;
        queue<TreeNode*>q;
        q.push(root);
        while(!q.empty()) {
            TreeNode* top = q.front();
            q.pop();
            if(top == NULL) {
                ans.append("#,");
            }
            else {
                ans.append(to_string(top->val) + ",");
            }
            if(top != NULL) {
                q.push(top->left);
                q.push(top->right);
            }
        }
        return ans;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        int n = data.length();
        if(n == 0) return NULL;
        stringstream s(data);
        string str;
        getline(s, str, ',');
        TreeNode* root = new TreeNode(stoi(str));
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()) {
            TreeNode* node = q.front();
            q.pop();
            getline(s, str, ',');
            if(str == "#") node->left = NULL;
            else {
                TreeNode* templeft = new TreeNode(stoi(str));
                node->left = templeft;
                q.push(templeft);
            }
            getline(s, str, ',');
            if(str == "#") node->right = NULL;
            else {
                TreeNode* tempright = new TreeNode(stoi(str));
                node->right = tempright;
                q.push(tempright);
            }
        }
        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));
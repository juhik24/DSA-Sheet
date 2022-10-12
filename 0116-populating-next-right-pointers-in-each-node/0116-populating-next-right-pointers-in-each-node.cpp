/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    // Time = O(n), Space = O(n)
    
    Node* connect(Node* root) {
        if(root == NULL) return root;
        if(root->left == NULL || root->right == NULL) return root;
        queue<Node*>q;
        q.push(root);
        while(!q.empty()) {
            int size = q.size();
            Node* temp = q.front();
            q.pop();
            for(int i = 0; i < size; i++) {
                Node* t = temp;
                if(size == 1 || i == size-1) {
                    temp->next = NULL;
                }
                else {
                    temp->next = q.front();
                    temp = q.front();
                    q.pop();
                }
                if(t->left) q.push(t->left);
                if(t->right) q.push(t->right);
            }
        }
        return root;
    }
};
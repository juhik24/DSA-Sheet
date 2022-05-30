/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        unordered_map<Node*, Node*>mp;
        mp[NULL] = NULL;
        Node* cur = head;
        while(cur) {
            Node* temp = new Node(cur->val);
            mp[cur] = temp;
            cur = cur->next;
        }
        cur = head;
        while(cur) {
            Node* temp = mp[cur];
            temp->next = mp[cur->next];
            temp->random = mp[cur->random];
            cur = cur->next;
        }
        return mp[head];
    }
};
/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};
*/

class Solution {
public:
    Node* solve(Node* head) {
       Node* cur = head, *temp = head;
        while(cur) {
            Node* child = cur->child;
            Node* next = cur->next;
            if(child) {
                Node* tail = solve(child);
                tail->next = next;
                if(next) next->prev = tail;
                cur->next = child;
                child->prev = cur;
                cur->child = NULL;
                cur = tail;
            }
            else {
                cur = next;
            }
            if(cur) temp = cur;
        }
        return temp;
    }
    
    Node* flatten(Node* head) {
        if(head) solve(head);
        return head;
    }
};
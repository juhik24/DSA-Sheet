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
    // Time = O(n), Space = O(n) for recursion stack
    
    Node* solve(Node* head) {
       Node* cur = head, *temp = head;
        while(cur) {
            Node* child = cur->child;
            Node* next = cur->next;
            // Every time we see a child we recursively call the function for child and insert it in b/w of cur and cur->next
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
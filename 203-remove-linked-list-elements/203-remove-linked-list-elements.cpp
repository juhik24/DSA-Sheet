/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        ListNode* temp1, *temp2;
        if(head == NULL) return head; 
        temp1 = head;
        temp2 = head->next;
        while(temp2) {
            if(temp2->val == val) {
                temp1->next = temp2->next;
            }
            else {
                temp1 = temp1->next;
            }
            temp2 = temp2->next;
        }
        if(head->val == val) head = head->next;
        return head;
    }
};
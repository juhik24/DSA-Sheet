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
    // Time = O(n), Space = O(1) 
    
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* temp = new ListNode(0);
        temp->next = head;
        ListNode* pred = temp;
        while(head) {
            if(head->next != NULL && head->val == head->next->val) {
                while(head->next != NULL && head->val == head->next->val) {
                    head = head->next;
                }
                pred->next = head->next;
            }
            else {
                pred = pred->next;
            }
            head = head->next;
        }
        return temp->next;;
    }
};
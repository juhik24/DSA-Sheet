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
    ListNode* reverse(ListNode* head) {
        ListNode* cur = head, *prev = NULL, *next;
        while(cur) {
            next = cur->next;
            cur->next = prev;
            prev = cur;
            cur = next;
        }
        head = prev;
        return head;
    }
    
    void reorderList(ListNode* head) {
        if(head==NULL || head->next == NULL) return ;
        ListNode* slow = head, *fast = head->next;
        while(fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }
        ListNode* temp = reverse(slow->next);
        slow->next = NULL;
        ListNode* cur = head, *curnext, *tempnext;
        while(cur && temp) {
            curnext = cur->next;
            tempnext = temp->next;
            cur->next = temp;
            temp->next = curnext;
            cur = curnext;
            temp = tempnext;
        }
        if(tempnext != NULL) temp->next = tempnext;
    }
};
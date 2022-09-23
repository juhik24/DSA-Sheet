/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        if(head == NULL|| head->next == NULL) return 0;
        
        ListNode* slow = head;
        ListNode* fast = head;
        
        slow = slow->next;
        fast = fast->next->next;
        
        while(fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
            if(slow == fast) break;
        }
        
        if(fast == NULL || fast->next == NULL) return 0;
        
        if(slow == head) {
            while(slow->next != fast) {
                slow = slow->next;
            }
            return slow->next;
        }
        
        if(slow == fast) {
            slow = head;
            while(slow->next != fast->next) {
                slow = slow->next;
                fast = fast->next;
            }
            return fast->next;
        }
        return 0;
    }
};
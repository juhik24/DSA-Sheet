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
    // Time = O(max(m, n)), Space = O(max(m, n)) 
    
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* head = NULL, *prev = NULL;
        int carry = 0;
        while(l1 || l2 || carry != 0) {
            int x = 0, y = 0;
            if(l1 != NULL) {
                x = l1->val;
                l1 = l1->next;
            }
            if(l2 != NULL) {
                y = l2->val;
                l2 = l2->next;
            }
            int digit = x + y + carry;
            carry = digit/10;
            int num = digit%10;
            ListNode * cur = new ListNode(num);
            if(head == NULL) head = cur;
            if(prev != NULL) prev->next = cur;
            prev = cur;
        }
        return head;
    }
};
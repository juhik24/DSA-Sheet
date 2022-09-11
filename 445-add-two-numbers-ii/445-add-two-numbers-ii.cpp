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
    
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        l1 = reverse(l1);
        l2 = reverse(l2);
        ListNode* head = NULL, *prev = NULL;
        int carry = 0;
        while(l1 || l2 || carry != 0) {
            int x = 0, y = 0;
            if(l1) {
                x = l1->val;
                l1 = l1->next;
            }
            if(l2) {
                y = l2->val;
                l2 = l2->next;
            }
            int num = x+y+carry;
            carry = num/10;
            int digit = num%10;
            ListNode* temp = new ListNode(digit);
            if(head == NULL) {
                head = temp;
            }
            if(prev != NULL) {
                prev->next = temp;
            }
            prev = temp;
        }
        head = reverse(head);
        return head;
    }
};
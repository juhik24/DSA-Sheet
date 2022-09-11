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
    
    ListNode* partition(ListNode* head, int x) {
        ListNode* before = new ListNode(0);
        ListNode* after = new ListNode(0);
        ListNode* cur = head, *btemp = before, *atemp = after;
        while(cur) {
            if(cur->val < x) {
                btemp->next = cur;
                btemp = cur;
            }
            else {
                atemp->next = cur;
                atemp = cur;
            }
            cur = cur->next;
        }
        btemp->next = after->next;
        atemp->next = NULL;
        return before->next;
    }
};
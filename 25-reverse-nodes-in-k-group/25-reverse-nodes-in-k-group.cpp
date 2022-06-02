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
    ListNode* getKth(ListNode* cur, int k) {
        while(cur && k > 0) {
            cur = cur->next;
            k--;
        }
        return cur;
    }
    
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        ListNode* groupPrev = dummy;
        while(1) {
            ListNode* kth = getKth(groupPrev, k);
            if(kth == NULL) break;
            
            ListNode* groupNext = kth->next;
            //reverse the group
            ListNode* prev = kth->next, *cur = groupPrev->next, *next;
            while(cur != groupNext) {
                next = cur->next;
                cur->next = prev;
                prev = cur;
                cur = next;
            }
            ListNode* temp = groupPrev->next;
            groupPrev->next = kth;
            groupPrev = temp;
        }
        return dummy->next;
    }
};
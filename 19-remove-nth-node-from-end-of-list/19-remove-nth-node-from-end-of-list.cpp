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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(head->next == NULL && n == 1) return NULL;
        int cnt = 0;
        ListNode* cur = head;
        while(cur) {
            cnt++;
            cur = cur->next;
        }
        if(cnt-n == 0) {
            head = head->next;
            return head;
        }
        cur = head;
        for(int i = 1; i < cnt-n; i++) {
            cur = cur->next;
        }
        cur->next = cur->next->next;
        return head;
    }
};
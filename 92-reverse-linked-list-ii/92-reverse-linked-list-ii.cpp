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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        ListNode* temp = new ListNode(0);
        temp->next = head;
        ListNode* leftPrev = temp, *cur = head;
        int i = 0;
        while(i < left-1) {
            leftPrev = cur;
            cur = cur->next;
            i++;
        }
        int n = right-left+1;
        ListNode* prev = NULL, *next;
        i = 0;
        while(i < n) {
            next = cur->next;
            cur->next = prev;
            prev = cur;
            cur = next;
            i++;
        }
        leftPrev->next->next = cur;
        leftPrev->next = prev;
        return temp->next;
    }
};
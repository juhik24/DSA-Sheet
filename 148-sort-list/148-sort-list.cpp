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
    ListNode* Merge(ListNode* first, ListNode* second) {
        ListNode* dummy = new ListNode(0);
        ListNode* temp = dummy;
        while(first && second) {
            if(first->val <= second->val) {
                temp->next = first;
                first = first->next;
            }
            else {
                temp->next = second;
                second = second->next;
            }
            temp = temp->next;
        }
        if(first) temp->next = first;
        else temp->next = second;
        return dummy->next;;
    }
    
    ListNode* getMid(ListNode* head) {
        ListNode* slow = head, *fast = head->next;
        while(fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }
        ListNode* mid = slow->next;
        slow->next = NULL;
        return mid;
    }
    
    ListNode* sortList(ListNode* head) {
        if(head == NULL || head->next == NULL) return head;
        ListNode* mid = getMid(head);
        ListNode* first = sortList(head);
        ListNode* second = sortList(mid);
        return Merge(first, second);
    }
};
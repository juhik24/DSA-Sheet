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
    
    int getDecimalValue(ListNode* head) {
        ListNode* temp = head;
        int num = 0;
        while(temp) {
            int digit = temp->val;
            num = (num*2) + digit;
            temp = temp->next;
        }
        return num;
    }
};
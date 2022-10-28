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
    ListNode* rotateRight(ListNode* head, int k) {
        if(head == NULL || head->next == NULL || k == 0) return head;
        ListNode* temp = head;
        int n = 1;
        while(temp->next) {
            n++;
            temp = temp->next;
        }
        k = k%n;
        k = n - k;
        temp->next = head;
        for(int i = 0; i < k; i++) {
           temp = temp->next;
        }
        head = temp->next;
        temp->next = NULL;
        return head;
    }
};

// Time = O(n*k), Space = O(1) 

// ListNode* rotateRight(ListNode* head, int k) {
//         if(head == NULL || head->next == NULL) return head;
//         ListNode* temp = head;
//         int n=0;
//         while(temp) {
//             n++;
//             temp = temp->next;
//         }
//         for(int i = 0; i < k; i++) {
//             temp = head;
//             while(temp->next->next) {
//                 temp = temp->next;
//             }
//             ListNode* node = temp->next;
//             temp->next = NULL;
//             node->next = head;
//             head = node;
//         }
//         return head;
//     }
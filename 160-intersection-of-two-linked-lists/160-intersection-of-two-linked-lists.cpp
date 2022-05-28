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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if(headA == NULL || headB == NULL) return NULL;
        ListNode* temp = NULL;
        int n1=0, n2=0;
        ListNode *temp1 = headA, *temp2 = headB;
        while(temp1) {
            n1++;
            temp1=temp1->next;
        }
        while(temp2) {
            n2++;
            temp2 = temp2->next;
        }
        if(n1 > n2) {
            while(n1 != n2) {
                headA = headA->next;
                n1--;
            }
        }
        else if(n2 > n1) {
            while(n2 != n1) {
                headB = headB->next;
                n2--;
            }
        }
        while(headA != headB) {
            if(headA == headB) {
                return headA;
            }
            headA = headA->next;
            headB = headB->next;
        }
        if(headA == headB) return headA;
        else return temp;
    }
};
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
    
    //Calculate the length of linked list.
    //if length is a multiple of k than after k times rotation it will return the original head.
    // And if len is not a multiple of k then we have to rotate the LL k%n times.
    // Like if len = 12 & k = 5 so k%n = 2. we have to rotate 2 times only. because if we rotate the LL 10 times it will give the original head. so we have to rotate only remaining 2 times.
    // For that we'll connect the last & first node & make it a circular LL.
    // Then we move from head till (k = k%n) n-kth node and change the pointers of head and tail.
    
    ListNode* rotateRight(ListNode* head, int k) {
        //edge cases
        if(head == NULL || head->next == NULL || k == 0) return head;
        ListNode* temp = head;
        int n = 1; // n = length
        while(temp->next) {
            n++;
            temp = temp->next;
        }
        
        // go till that node i.e,n-kth
        k = k%n;
        k = n - k;
        temp->next = head;
        for(int i = 0; i < k; i++) {
           temp = temp->next;
        }
        // make the node head & break connection
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
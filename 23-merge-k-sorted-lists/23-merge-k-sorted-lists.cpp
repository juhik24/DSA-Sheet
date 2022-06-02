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
    ListNode* solve(ListNode* first, ListNode* second) {
        if(first == NULL) return second;
        if(second == NULL) return first;
        ListNode* dummy = new ListNode(0);
        ListNode* temp=dummy;
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
        return dummy->next;
    }
    
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        int n = lists.size();
        ListNode* ans = NULL;
        for(int i = 0; i < n; i++) {
            ans = solve(ans, lists[i]);
        }
        return ans;
    }
};
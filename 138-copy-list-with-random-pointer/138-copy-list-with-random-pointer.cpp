/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    // Optimised -> Time = O(n), Space = O(1) 
    
    // Step 1 - We'll create copy of every node and insert it in between original nodes.
    // Step 2 - For assigning random to our copy nodes, copy node's random(itr->next->random) = next of random of original node (itr->random->next).
    // Step 3 - Now we change the pointers to separate original nodes and copy nodes.
    
    Node* copyRandomList(Node* head) {
        Node* itr = head;
        Node* front = head;
        // Make copy of each node and link them together side by side.
        while(itr != NULL) {
            front = itr->next;
            Node* copy = new Node(itr->val);
            itr->next = copy;
            copy->next = front;
            itr = front;
        }
        // Assign random pointers for copy nodes
        itr = head;
        while(itr != NULL) {
            if(itr->random != NULL) {
                itr->next->random = itr->random->next;
            }
            itr = itr->next->next;
        }
        // Restore the original list and extract the copy list
        itr = head;
        Node* temp = new Node(0);
        Node* copy = temp;
        while(itr != NULL) {
            front = itr->next->next;
            //extract the copy
            copy->next = itr->next;
            //restore the original list
            itr->next = front;
            copy = copy->next;
            itr = front;
        }
        return temp->next;
    }
};

// Brute force = Time = O(n), Space = O(n) 

// Node* copyRandomList(Node* head) {
//         // unordered_map will store copy of every node, i.e, mp[node1] = copyNode1
//         unordered_map<Node*, Node*>mp;
//         mp[NULL] = NULL;
//         Node* cur = head;
//         while(cur) {
//             Node* temp = new Node(cur->val);
//             mp[cur] = temp;
//             cur = cur->next;
//         }
//         cur = head;
//         // Traverse the linked list again change the pointers of copy nodes
//         while(cur) {
//             Node* temp = mp[cur];
//             temp->next = mp[cur->next];
//             temp->random = mp[cur->random];
//             cur = cur->next;
//         }
//         return mp[head];
//     }
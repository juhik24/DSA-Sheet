// { Driver Code Starts
// driver

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
using namespace std;

/* Linked list Node */
struct Node {
    int data;
    struct Node* next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

struct Node* buildList(int size)
{
    int val;
    cin>> val;
    
    Node* head = new Node(val);
    Node* tail = head;
    
    for(int i=0; i<size-1; i++)
    {
        cin>> val;
        tail->next = new Node(val);
        tail = tail->next;
    }
    
    return head;
}

void printList(Node* n)
{
    while(n)
    {
        cout<< n->data << " ";
        n = n->next;
    }
    cout<< endl;
}

Node* subLinkedList(Node* l1, Node* l2);

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n, m;
        
        cin>>n;
        Node* first = buildList(n);
        
        cin>>m;
        Node* second = buildList(m);
        
        Node* res = subLinkedList(first,second);
        printList(res);
    }
    return 0;
}
// } Driver Code Ends


/* Structure of linked list Node

struct Node
{
    int data;
    struct Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
    
};

*/

//You are required to complete this method

Node* reverse(Node* head) {
    if(head == NULL || head->next == NULL) return head;
    Node* cur = head, *prev = NULL, *next;
    while(cur) {
        next = cur->next;
        cur->next = prev;
        prev = cur;
        cur = next;
    }
    head = prev;
    return prev;
}

Node* padzeros(Node* head) {
    while(head->data == 0 && head->next != NULL) {
        head = head->next;
    }
    return head;
}

int getLength(Node* head) {
    int cnt = 0;
    while(head) {
        cnt++;
        head = head->next;
    }
    return cnt;
}

Node* getMax(Node* l1, Node* l2) {
    Node* cur_l1 = l1, *cur_l2 = l2;
    while(cur_l1 && cur_l2) {
        if(cur_l1->data > cur_l2->data) return l1;
        else if(cur_l2->data > cur_l1->data) return l2;
        else {
            cur_l1 = cur_l1->next;
            cur_l2 = cur_l2->next;
        }
    }
    return l1;
}

Node* subLinkedList(Node* l1, Node* l2)
{
    //Your code here
    Node* ans = new Node(0);
    Node* temp = ans;
    l1 = padzeros(l1);
    l2 = padzeros(l2);
    int len1 = getLength(l1);
    int len2 = getLength(l2);
    Node* temp1 = l1, *temp2 = l2;
    Node* first = NULL, *second = NULL;
    if(len1 == len2) {
       first = getMax(l1, l2);
       if(first == l1) second = l2;
       else second = l1;
       first = reverse(first);
       second = reverse(second);
    }
    else {
        l1 = reverse(l1);
        l2 = reverse(l2);
        if(len1 > len2) {
            first = l1;
            second = l2;
        }
        else if(len2 > len1) {
            first = l2;
            second = l1;
        }
    }
    
    int borrow = 0;
    while(first || second) {
        int x = 0, y = 0;
        if(first) {
            x = first->data;
            first = first->next;
        }
        if(second) {
            y = second->data;
            second = second->next;
        }
        int diff = (x-y)+borrow;
        if(diff < 0) {
            borrow = -1;
            diff += 10;
        }
        else borrow = 0;
        Node* node = new Node(diff);
        temp->next = node;
        temp = temp->next;
    }
    Node* head = reverse(ans->next);
    if(head->data == 0) {
        while(head->next != NULL) {
            if(head->data != 0) break;
            else head = head->next;
        }
    }
    return head;
}
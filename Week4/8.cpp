#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    struct Node* next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};


 // } Driver Code Ends
/* Structure of the linked list node is as
struct Node 
{
    int data;
    struct Node* next;
    Node(int x) { data = x;  next = NULL; }
};
*/


class Solution{
private: 
    Node* splitList(Node* head){
        Node* temp = NULL;
        Node* slow = head;
        Node* fast = head;
        while(fast && fast->next){
            temp = slow;
            slow = slow->next;
            fast = fast->next->next;
        }
        temp->next = NULL;
        return slow;
    }
    Node* merge(Node* head1, Node* head2) {
        Node* head;
        if(!head1)
            return head2;
        if(!head2)
            return head1;
        if(head1->data <= head2->data){
            head = head1;
            head1->next = merge(head1->next, head2);
        }
        else {
            head = head2;
            head2->next = merge(head1, head2->next);
        }
        return head;
    }
  public:
    //Function to sort the given linked list using Merge Sort.
    Node* mergeSort(Node* head) {
        // your code here
        Node* second;
        if(!head || !head->next)
            return head;
        second = splitList(head);
        head = mergeSort(head);
        second = mergeSort(second);
        return merge(head, second);
    }
};


// { Driver Code Starts.

void printList(Node* node) {
    while (node != NULL) {
        printf("%d ", node->data);
        node = node->next;
    }
    printf("\n");
}

void push(struct Node** head_ref, int new_data) {
    Node* new_node = new Node(new_data);

    new_node->next = (*head_ref);
    (*head_ref) = new_node;
}

int main() {
    long test;
    cin >> test;
    while (test--) {
        struct Node* a = NULL;
        long n, tmp;
        cin >> n;
        for (int i = 0; i < n; i++) {
            cin >> tmp;
            push(&a, tmp);
        }
        Solution obj;
        a = obj.mergeSort(a);
        printList(a);
    }
    return 0;
}  // } Driver Code Ends

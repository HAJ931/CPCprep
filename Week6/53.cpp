#include <bits/stdc++.h>
using namespace std;

class Node{
    public:
    int data;
    Node* prev;
    Node* next;
};

void push(Node** head_ref, int new_data) 
{ 
    Node* new_node = new Node();
    new_node->data = new_data; 
    new_node->prev = NULL; 
    new_node->next = (*head_ref); 
  
    if((*head_ref) != NULL) 
        (*head_ref)->prev = new_node; 
    (*head_ref) = new_node; 
}

Node* convertToBSTUtil(Node** headRef, int n){
    if(n <= 0)
        return NULL;
    Node* left = convertToBSTUtil(headRef, n / 2);
    Node* root = *headRef;
    root->prev = left;
    *headRef = (*headRef)->next;
    root->next = convertToBSTUtil(headRef, n - n / 2 - 1);
    return root;
}

Node* convertToBST(Node* headRef){
    if(!(headRef))
        return NULL;
    int n = 0;
    Node* temp = headRef;
    while(temp){
        temp = temp->next;
        ++n;
    }
    return convertToBSTUtil(&headRef, n);
}

void preOrder(Node *root){
    if(!root)
        return;
    cout << root->data << " ";
    preOrder(root->prev);
    preOrder(root->next);
}

int main() {

    Node* head = NULL; 
    push(&head, 7); 
    push(&head, 6); 
    push(&head, 5); 
    push(&head, 4); 
    push(&head, 3); 
    push(&head, 2); 
    push(&head, 1);
    
    Node *root = convertToBST(head); 
    cout<<"\nPreOrder Traversal of constructed BST \n "; 
    preOrder(root); 
  
    return 0; 
    
}

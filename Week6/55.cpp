#include<bits/stdc++.h>
using namespace std;

class LLNode {
    public:
    int data;
    LLNode* next;
};

class Node {
    public:
    int data;
    Node* left;
    Node* right;
    Node(int x){
        this->data = x;
        this->left = NULL;
        this->right = NULL;
    }
};

Node* constructBSTUtil(LLNode** headRef, int n){
    if(n <= 0)
        return NULL;
    Node* left = constructBSTUtil(headRef, n / 2);
    Node* root = new Node((*headRef)->data);
    root->left = left;
    *headRef = (*headRef)->next;
    root->right = constructBSTUtil(headRef, n - n / 2 - 1);
    return root;
}

Node* constructBST(LLNode* headRef){
    if(!headRef)
        return NULL;
    int n = 0;
    LLNode* temp = headRef;
    while(temp){
        ++n;
        temp = temp->next;
    }
    Node* root = constructBSTUtil(&headRef, n);
    return root;
}

void push(LLNode** head_ref, int new_data) 
{ 
    LLNode* new_node = new LLNode();
    new_node->data = new_data; 
    new_node->next = (*head_ref); 
    (*head_ref) = new_node; 
}

void preOrder(Node* root){
    if(!root)
        return;
    cout << root->data << " ";
    preOrder(root->left);
    preOrder(root->right);
}


int main(){
    LLNode* head = NULL; 
    push(&head, 7); 
    push(&head, 6); 
    push(&head, 5); 
    push(&head, 4); 
    push(&head, 3); 
    push(&head, 2); 
    push(&head, 1);
    Node* root = constructBST(head);
    preOrder(root);
}

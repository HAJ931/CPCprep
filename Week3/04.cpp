#include <bits/stdc++.h>
using namespace std;

class Node{
    public:
        int data;
        Node* next;
    
};

void printReverse(Node *head){
    if(head == NULL)
        return;
    printReverse(head->next);
    cout << head->data << " ";
}

void pushNode(Node **head, int newData){
    Node *newNode = new Node();
    newNode->data = newData;
    newNode->next = *head;
    *head = newNode;
}

int main(){
    Node* head = NULL;
    
    pushNode(&head, 3);
    pushNode(&head, 2);
    pushNode(&head, 1);
    
    printReverse(head);
    return 0;
}

#include <bits/stdc++.h>
using namespace std;

class Node{
    public:
        int data;
        Node* next;
    
};

void delList(Node **head){
    Node *curr = *head;
    Node *nex = NULL;
    while(curr != NULL){
        nex = curr->next;
        free(curr);
        curr = nex;
    }
    
    *head = NULL;
    cout << "List successfully deleted" << endl;
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
    
    delList(&head);
    return 0;
}

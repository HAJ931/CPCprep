#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
        int data;
        Node *next;

};

Node* reverseAlt(Node * head, int k){
    Node *prev = NULL;
    Node *curr = head;
    Node *nex = NULL;
    int count = 0;
    //Reverse k nodes
    while(count < k && curr){
        nex = curr->next;
        curr->next = prev;
        prev = curr;
        curr = nex;
        ++count;
    }
    if(head)
        head->next = curr;
    //Skip over next k nodes
    count = 0;
    while(count < k - 1 && curr){
        curr = curr->next;
        count++;
    }
    //Call function recursively for the next set of k + k nodes
    if(curr){
        curr->next = reverseAlt(curr->next, k);
    }
    
    return prev;
}

void pushNode (Node ** head, int newData){
    Node *newNode = new Node();
    newNode->data = newData;
    newNode->next = *head;
    *head = newNode;
}

void printList(Node * node){
    while(node != NULL){
        cout << node->data << " ";
        node = node->next;
    }
    cout << "\n";
}

int main(){
    Node *head = NULL;
    int n;
    cin >> n;
    for(int i = 0; i < n; ++i){
        int temp;
        cin >> temp;
        pushNode(&head, temp);
    }
    int k;
    cin >> k;
    cout << "k is " << k << endl;
    printList(head);
    head = reverseAlt(head, k);
    printList(head);
}

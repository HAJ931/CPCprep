#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
        int data;
        Node *left;
        Node *right;
    
    Node(int data){
        this->data = data;
        this->left = NULL;
        this->right = NULL;
    }

};

void delTree(Node* p){
    if(!p)
        return;
    delTree(p->left);
    delTree(p->right);
    cout << "Deleting node " << p->data << endl;
    delete p;
}

int main(){
    Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    delTree(root);
}

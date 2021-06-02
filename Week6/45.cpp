#include<bits/stdc++.h>
using namespace std;

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

Node* removeRange(Node* root, int low, int high){
    if(!root)
        return NULL;
    root->left = removeRange(root->left, low, high);
    root->right = removeRange(root->right, low, high);
    
    if(root->data < low){
        Node* rST = root->right;
        free(root);
        return rST;
    }
    else if(root->data > high){
        Node *lST = root->left;
        free(root);
        return lST;
    }
    else
        return root;
    
}

void inOrder(Node* root){
    if(!root)
        return;
    inOrder(root->left);
    cout << root->data << " ";
    inOrder(root->right);
}


int main(){
    Node* n1 = new Node(6);
    n1->left = new Node(-13);
    n1->right = new Node(14);
    n1->left->right = new Node(-8);
    n1->right->left = new Node(13);
    n1->right->right = new Node(15);
    n1->right->left->left = new Node(7);
    n1 = removeRange(n1, -10, 13);
    inOrder(n1);
}

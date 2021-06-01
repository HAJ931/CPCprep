#include <bits/stdc++.h>
using namespace std;

class Node{
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

void refineDown(Node* root, int diff){
    if(!root)
        return;
    root->data += diff;
    if(root->left)
    refineDown(root->left, diff);
    else if(root->right)
    refineDown(root->right, diff);
}

void makeSumTree(Node* root){
    if(!root || !root->left && !root->right){
        return;
    }
    makeSumTree(root->left);
    makeSumTree(root->right);
    int left = 0, right = 0;
    if(root->left)
        left = root->left->data;
    if(root->right)
        right = root->right->data;
    if(root->data < left + right)
        root->data = left + right;
    else if(root->data > left + right)
        refineDown(root->left, root->data - (left + right));
    return;
}

void preOrder(Node *root){
    if(!root)
        return;
    cout << root->data << " ";
    preOrder(root->left);
    preOrder(root->right);
}

int main() {
    Node* n1 = new Node(50);
    n1->left = new Node(7);
    n1->right = new Node(2);
    //n1->left->left = new Node(3);
    n1->left->right = new Node(5);
    n1->right->left = new Node(1);
    n1->right->right = new Node(30);
    makeSumTree(n1);
    preOrder(n1);
    
}

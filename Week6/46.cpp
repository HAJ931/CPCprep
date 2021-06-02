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

Node* convertTree(Node* root, int k){
    if(!root)
        return NULL;
    
    root->left = convertTree(root->left, k - root->data);
    root->right = convertTree(root->right, k - root->data);
    
    if(!root->left && !root->right)
        if(k > root->data){
            free(root);
            return NULL;
        }
    return root;
}

void inOrder(Node* root){
    if(!root)
        return;
    inOrder(root->left);
    cout << root->data << " ";
    inOrder(root->right);
}

int main() {
	Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);
    root->left->left->left = new Node(8);
    root->left->left->right = new Node(9);
    root->left->right->left = new Node(12);
    root->right->right->left = new Node(10);
    root->right->right->left->right = new Node(11);
    root->left->left->right->left = new Node(13);
    root->left->left->right->right = new Node(14);
    root->left->left->right->right->left = new Node(15);
    convertTree(root, 45);
    inOrder(root);
    
}

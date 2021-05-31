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

void buildDup(Node *root){
    if(!root)
        return;
    //Post order traversal of the tree
    buildDup(root->left);
    buildDup(root->right);
    
    Node* temp = root->left;
    root->left = new Node(root->data);
    root->left->left = temp;
}

void preOrderTraversal(Node *root){
    if(!root)
        return;
    cout << root->data << " ";
    preOrderTraversal(root->left);
    preOrderTraversal(root->right);
}

int main() {
	Node* root = new Node(1);
	root->left = new Node(2);
	root->right = new Node(3);
	buildDup(root);
	cout << "The pre-order traversal of the new tree is: ";
	preOrderTraversal(root);
}

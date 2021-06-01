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

void convertTree(Node* root){
    if(!root)
        return;
    stack<Node*> s;
    int sum = 0;
    Node* temp = root;
    while(!s.empty() || temp){
        while(temp){
            s.push(temp);
            temp = temp->right;
        }
        temp = s.top();
        s.pop();
        sum += temp->data;
        temp->data = sum;
        temp = temp->left;
    }
    return;
}

void inOrder(Node* root){
    if(!root)
        return;
    inOrder(root->left);
    cout << root->data << " ";
    inOrder(root->right);
}

int main() {
	Node* n1 = new Node(8);
    n1->left = new Node(5);
    n1->right = new Node(12);
    n1->left->left = new Node(2);
    n1->left->right = new Node(7);
    n1->right->left = new Node(9);
    n1->right->right = new Node(15);
    convertTree(n1);
    inOrder(n1);
    
}

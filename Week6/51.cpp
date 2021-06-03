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

void printAncestors(Node* root, int k){
    if(!root)
        return;
    stack<Node*> s;
    Node* temp = root;
    while(true){
        while(temp && temp->data != k){
            s.push(temp);
            temp = temp->left;
        }
        
        if(temp && temp->data == k){
            break;
        }
        
        if(!s.top()->right){
            temp = s.top();
            s.pop();
            
            while(!s.empty() && s.top()->right == temp){
                temp = s.top();
                s.pop();
            }
        }
        
        temp = s.empty() ? NULL : s.top()->right;
    }
    
    while(!s.empty()){
        temp = s.top();
        cout << temp->data << " ";
        s.pop();
    }
}

int main() {
	Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);
    root->left->left->left = new Node(8);
    root->left->right->right = new Node(9);
    root->right->right->left = new Node(10);
    printAncestors(root, 10);
    
}

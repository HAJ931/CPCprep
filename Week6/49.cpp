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

void preOrder(Node* root, int& sum, int& currSum, Node** target){
    if(!root)
        return;
    currSum += root->data;
    if(!root->left && !root->right && sum < currSum){
        *target = root;
        sum = currSum;
    }
    preOrder(root->left, sum, currSum, target);
    preOrder(root->right, sum, currSum, target);
}

bool printPath(Node* root,Node* target){
    if(!root)
        return false;
    if(root == target || printPath(root->left, target) || printPath(root->right, target)){
        cout << root->data << " ";
        return true;
    }
    return false;
}

Node* findPath(Node* root){
    if(!root)
        return NULL;
    
    int sum = 0, currSum = 0;
    Node* target = NULL;
    preOrder(root, sum, currSum, &target);
    cout << "The maximum sum is: " << sum << endl;
    cout << "The path is: ";
    printPath(root, target);
    
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
	Node* root = new Node(10);
    root->left = new Node(-2);
    root->right = new Node(7);
    root->left->left = new Node(8);
    root->left->right = new Node(-4);
    findPath(root);
    
}

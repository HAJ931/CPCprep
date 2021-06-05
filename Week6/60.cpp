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

int maxIndex(vector<int>& arr, int low, int high){
    int max = INT_MIN, index = low;
    for(int i = low; i <= high; ++i){
        if(arr[i] > max){
            max = arr[i];
            index = i;
        }
    }
    return index;
}

Node* buildTreeUtil(vector<int>& in, int low, int high){
    if(high < low)
        return NULL;
    int rootIndex = maxIndex(in, low, high);
    Node* root = new Node(in[rootIndex]);
    root->left = buildTreeUtil(in, low, rootIndex - 1);
    root->right = buildTreeUtil(in, rootIndex + 1, high);
    return root;
}

Node* buildTree(vector<int> in, int n){
    Node* root = buildTreeUtil(in, 0, n - 1);
    return root;
}

void preOrder(Node* root){
    if(!root)
        return;
    cout << root->data << " ";
    preOrder(root->left);
    preOrder(root->right);
}

int main() {
    vector<int> inorder = {5, 10, 40, 30, 28};
	Node* root = buildTree(inorder, inorder.size());
	cout << "Preorder traversal of the constructed tree is: ";
	preOrder(root);
	return 0;
    
}

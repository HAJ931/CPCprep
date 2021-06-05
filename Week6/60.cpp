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

Node* buildTreeUtil(vector<int>& pre, vector<char>& preLN, int& index){
    if(index >= pre.size())
        return NULL;
    Node* root = new Node(pre[index]);
    if(preLN[index++] == 'N'){
        root->left = buildTreeUtil(pre, preLN, index);
        root->right = buildTreeUtil(pre, preLN, index);
    }
    return root;
}

Node* buildTree(vector<int>& pre, vector<char>& preLN){
    int index = 0;
    Node* root = buildTreeUtil(pre, preLN, index);
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
    vector<int> pre = {10, 30, 20, 5, 15};
    vector<char> preLN = {'N', 'N', 'L', 'L', 'L'};
	Node* root = buildTree(pre, preLN);
	cout << "Inorder traversal of the constructed tree is: ";
	inOrder(root);
	return 0;
    
}

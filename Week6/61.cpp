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

Node* buildTreeUtil(vector<int>& pre, vector<int>& post, map<int, int>& hMap, int& preIndex, int low, int high){
    if(preIndex >= pre.size() || low > high)
        return NULL;
    
    Node* root = new Node(pre[preIndex++]);
    int postIndex = hMap[pre[preIndex]];
    if(low == high)
        return root;
    if(postIndex <= high){
        root->left = buildTreeUtil(pre, post, hMap, preIndex, low, postIndex);
        root->right = buildTreeUtil(pre, post, hMap, preIndex, postIndex + 1, high);
    }
    return root;
}

Node* buildTree(vector<int>& pre, vector<int>& post){
    int index = 0;
    map<int, int> hMap;
    for(int i = 0; i < post.size(); ++i){
        hMap[post[i]] = i; 
    }
    Node* root = buildTreeUtil(pre, post, hMap, index, 0, post.size() - 1);
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
    vector<int> pre = {1, 2, 4, 8, 9, 5, 3, 6, 7};
    vector<int> post = {8, 9, 4, 5, 2, 6, 7, 3, 1};
	Node* root = buildTree(pre, post);
	cout << root->data << " ";
	cout << "Inorder traversal of the constructed tree is: ";
	inOrder(root);
	return 0;
    
}

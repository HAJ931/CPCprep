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

vector<int> mergeArr(vector<int> arr1, vector<int> arr2){
    vector<int> ans;
    int i = 0, j = 0, m = arr1.size(), n = arr2.size();
    while(i < m && j < n){
        if(arr1[i] < arr2[j]){
            ans.push_back(arr1[i]);
            ++i;
        }
        else if(arr1[i] > arr2[j]){
            ans.push_back(arr2[j]);
            ++j;
        }
        else{
            ans.push_back(arr1[i]);
            ++i;
            ++j;
        }
    }
    while(i < m){
        ans.push_back(arr1[i]);
            ++i;
    }
    while(j < n){
        ans.push_back(arr2[j]);
            ++j;
    }
    cout << "The merged array is: ";
    for(int i = 0; i < ans.size(); ++i){
        cout << ans[i] << " ";
    }
    cout << endl;
    return ans;
}

Node* makeBSTUtil(vector<int>& arr, int low, int high){
    if(low > high)
        return NULL;
    int mid = low + (high - low) / 2;
    Node* root = new Node(arr[mid]);
    root->left = makeBSTUtil(arr, low, mid - 1);
    root->right = makeBSTUtil(arr, mid + 1, high);
    return root;
}

Node* makeBST(vector<int> arr){
    int n = arr.size();
    Node* root = makeBSTUtil(arr, 0, n - 1);
    return root;
}

void inOrder(Node* root){
    if(!root)
        return;
    inOrder(root->left);
    cout << root->data << " ";
    inOrder(root->right);
}

void storeInOrder(Node* root, vector<int>& arr){
    if(!root)
        return;
    storeInOrder(root->left, arr);
    arr.push_back(root->data);
    storeInOrder(root->right, arr);
}

void preOrder(Node* root){
    if(!root)
        return;
    cout << root->data << " ";
    preOrder(root->left);
    preOrder(root->right);
}

int main() {
    Node *root1 = new Node(100);
    root1->left = new Node(50);
    root1->right = new Node(300);
    root1->left->left = new Node(20);
    root1->left->right = new Node(70);
	
	Node *root2 = new Node(80);
    root2->left = new Node(40);
    root2->right = new Node(120);
    
    vector<int> arr1, arr2;
    storeInOrder(root1, arr1);
    storeInOrder(root2, arr2);
	vector<int> arr = mergeArr(arr1, arr2);
	Node* root = makeBST(arr);
	cout << "Pre Order traversal of the constructed tree is: ";
	preOrder(root);
	cout << "\nInorder traversal of the constructed tree is: ";
	inOrder(root);
	return 0;
    
}

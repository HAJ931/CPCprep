//

#include<bits/stdc++.h>
using namespace std;

struct Node
{
	int data;
	struct Node *left;
	struct Node *right;
	
	Node(int x){
	    data = x;
	    left = NULL;
	    right = NULL;
	}
};


void printPostOrder(Node *root)
{
	if(root==NULL)
		return;
	printPostOrder(root->left);
	printPostOrder(root->right);
	cout<<root->data<<" ";
}

 // } Driver Code Ends


/*Complete the code here.
Node is as follows:
struct Node
{
  int data;
  Node* left;
  Node* right;
};
*/
class Solution{
    private: 
    Node* buildTreeUtil(int in[], int pre[], map<int, int>& hMap, int& preIndex, int low, int high){
        if(high < low)
            return NULL;
        int inIndex = hMap[pre[preIndex++]];
        Node* root = new Node(in[inIndex]);
        root->left = buildTreeUtil(in, pre, hMap, preIndex, low, inIndex - 1);
        root->right = buildTreeUtil(in, pre, hMap, preIndex, inIndex + 1, high);
        return root;
    }
    public:
    Node* buildTree(int in[],int pre[], int n)
    {
        // Code here
        map<int, int> hMap;
        int preIndex = 0;
        for(int i = 0; i < n; ++i){
            hMap[in[i]] = i;
        }
        Node* root = buildTreeUtil(in, pre, hMap, preIndex, 0, n - 1);
        return root;
    }
};

// { Driver Code Starts.
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		
		int inorder[n], preorder[n];
		for(int i=0; i<n; i++)
			cin>> inorder[i];
		for(int i=0; i<n; i++)
			cin>> preorder[i];
		Solution obj;
		Node *root = obj.buildTree(inorder, preorder, n);
		printPostOrder(root);
		cout<< endl;
	}
}
  // } Driver Code Ends

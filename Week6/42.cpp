#include <bits/stdc++.h>
using namespace std;
#define MAX_HEIGHT 100000
#define MAX_SIZE 100000

// Tree Node
struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};

// Function to Build Tree
Node* buildTree(string str)
{
   // Corner Case
   if(str.length() == 0 || str[0] == 'N')
       return NULL;

   // Creating vector of strings from input
   // string after spliting by space
   vector<string> ip;

   istringstream iss(str);
   for(string str; iss >> str; )
       ip.push_back(str);

   // Create the root of the tree
   Node* root = new Node(stoi(ip[0]));

   // Push the root to the queue
   queue<Node*> queue;
   queue.push(root);

   // Starting from the second element
   int i = 1;
   while(!queue.empty() && i < ip.size()) {

       // Get and remove the front of the queue
       Node* currNode = queue.front();
       queue.pop();

       // Get the current node's value from the string
       string currVal = ip[i];

       // If the left child is not null
       if(currVal != "N") {

           // Create the left child for the current node
           currNode->left = new Node(stoi(currVal));

           // Push it to the queue
           queue.push(currNode->left);
       }

       // For the right child
       i++;
       if(i >= ip.size())
           break;
       currVal = ip[i];

       // If the right child is not null
       if(currVal != "N") {

           // Create the right child for the current node
           currNode->right = new Node(stoi(currVal));

           // Push it to the queue
           queue.push(currNode->right);
       }
       i++;
   }

   return root;
}

 // } Driver Code Ends
/*Complete the function below
Node is as follows
struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};
*/

class Solution{
  public:
    // root : the root Node of the given BST
    // target : the target sum
    int isPairPresent(struct Node *root, int target)
    {
    //add code here.
    if(!root)
        return 0;
    stack<Node*> s1, s2;
    bool done1 = false, done2 = false;
    int num1 = 0, num2 = 0;
    Node* temp1 = root, *temp2 = root;
    while(true){
        //Inorder traversal of left subtree of root
        while(!done1){
            if(temp1){
                s1.push(temp1);
                temp1= temp1->left;
            }
            else{
                if(s1.empty())
                    done1 = true;
                else{
                    temp1 = s1.top();
                    s1.pop();
                    num1 = temp1->data;
                    temp1 = temp1->right;
                    done1 = true;
                }
            }
        }
        //Reverse Inorder Traversal of right subtree of root
        while(!done2){
            if(temp2){
                s2.push(temp2);
                temp2 = temp2->right;
            }
            else{
                if(s2.empty())
                    done2 - true;
                else{
                    temp2 = s2.top();
                    s2.pop();
                    num2 = temp2->data;
                    temp2 = temp2->left;
                    done2 = true;
                }
            }
        }
        
        if((num1 != num2) && (num1 + num2) == target){
            return 1;
        }
        
        else if((num1 + num2) < target)
            done1 = false;
        
        else if((num1 + num2) > target)
            done2 = false;
        
        if(num1 >= num2)
            return 0;
    }
    return 0;
    }
};

// { Driver Code Starts.
int main() {
    
   int t;
   string tc;
   getline(cin, tc);
   t=stoi(tc);
   while(t--)
   {
        string s; 
       getline(cin, s);
       Node* root = buildTree(s);

       getline(cin, s);
       int k = stoi(s);
        //getline(cin, s);
       Solution obj;    
       cout << obj.isPairPresent(root, k) << endl;
       //cout<<"~"<<endl;
   }
   return 0;
}
  // } Driver Code Ends

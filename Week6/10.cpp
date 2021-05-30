#include <bits/stdc++.h>
using namespace std;

// Tree Node
struct Node
{
    int data;
    Node* left;
    Node* right;
    Node* nextRight;
};

// Utility function to create a new Tree Node
Node* newNode(int val)
{
    Node* temp = new Node;
    temp->data = val;
    temp->left = NULL;
    temp->right = NULL;
    temp->nextRight = NULL;
    
    return temp;
}

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
    Node* root = newNode(stoi(ip[0]));
        
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
            currNode->left = newNode(stoi(currVal));
                
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
            currNode->right = newNode(stoi(currVal));
                
            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }
    
    return root;
}

void connect(struct Node *p);

/* Helper function that allocates a new node with the
   given data and NULL left and right pointers. */


void printSpecial(Node *root)
{
   if (root == NULL)
     return;

   Node* next_root=NULL;

   while (root != NULL)
   {
      cout<< root->data<<" ";

      if( root->left && (!next_root) )
        next_root = root->left;
      else if( root->right && (!next_root)  )
        next_root = root->right;

      root = root->nextRight;
   }
   
   printSpecial(next_root);
}

void inorder(Node *root)
{
    if (root == NULL)
       return;
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}


 // } Driver Code Ends
/* struct Node
{
  int data;
  Node *left,  *right;
  Node *nextRight;  // This has garbage value in input trees
}; */


class Solution
{
    private:
    Node* getNextRight(Node* p){
      //This will return what the child nodes need to connect to next, using the parent node info passed
        Node* temp = p->nextRight;
        while(temp){
            if(temp->left)
                return temp->left;
            if(temp->right)
                return temp->right;
            temp = temp->nextRight;
        }
        return NULL;
    }
    public:
    //Function to connect nodes at same level.
    void connect(Node *root)
    {
       // Your Code Here
       Node* p = root;
      //Next Right of root is always null
       p->nextRight = NULL;
       while(p){
         //Traverse each level and connect child nodes to each other in sequence
           Node *q = p;
           while(q){
               if(q->left){
                   if(q->right){
                     //If left and right children exist, then next right of left child is the right child
                       q->left->nextRight = q->right;
                   }
                   else
                     //If right child doesnt exist, find out the next node left child can connect to
                   q->left->nextRight = getNextRight(q);
               }
             //As above
               if(q->right){
                   q->right->nextRight = getNextRight(q);
               }
               q = q->nextRight;
           }
         //After traversing a level, we now set p to the leftmost node of the next level
           if(p->left)
             //Left child exists, then first node of next level is the left child of the first node of this level
                p = p->left;
            else if(p->right)
              //If left doesn't exist, then right would be first node of next level
                p = p->right;
            else
              //Otherwise find the next node in the next level using getNextRight
            p = getNextRight(p);
       }
    }    
      
};




// { Driver Code Starts.


/* Driver program to test size function*/
int main()
{
  int t;
  scanf("%d\n", &t);
  while (t--)
  {
     string s;
     getline(cin, s);
     Node* root = buildTree(s);
        
    Solution obj;
     obj.connect(root);
     printSpecial(root);
     cout<<endl;
     inorder(root);
     cout<<endl;
  }
  return 0;
}
  // } Driver Code Ends

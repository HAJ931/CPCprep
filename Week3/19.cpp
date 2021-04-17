//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
};
void printList(Node* node) 
{ 
    while (node != NULL) { 
        cout << node->data <<" "; 
        node = node->next; 
    }  
    cout<<"\n";
} 


 // } Driver Code Ends
//User function template for C++

/*
struct Node
{
    int data;
    struct Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
};
*/
class Solution{
public:
    Node* divide(int N, Node *head){
        // code here
        Node *evenStart = NULL;
        Node *evenEnd = NULL;
        Node *oddStart = NULL;
        Node *oddEnd = NULL;
        Node *curr = head;
        while(curr){
            if(curr->data % 2 == 0){
                if(!evenStart){
                    evenStart = curr;
                    evenEnd = evenStart;
                }
                else{
                    evenEnd->next = curr;
                    evenEnd = evenEnd->next;
                }
            }
            else{
                if(!oddStart){
                    oddStart = curr;
                    oddEnd = oddStart;
                }
                else{
                    oddEnd->next = curr;
                    oddEnd = oddEnd->next;
                }
            }
            curr = curr->next;
        }
        if(!oddStart || !evenStart)
                return head;
        evenEnd->next = oddStart;
        oddEnd->next = NULL;
        return evenStart;
    }
};

// { Driver Code Starts.

int main() {
    //code
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        int data;
        cin>>data;
        struct Node *head = new Node(data);
        struct Node *tail = head;
        for (int i = 0; i < N-1; ++i)
        {
            cin>>data;
            tail->next = new Node(data);
            tail = tail->next;
        }
        
        Solution ob;
        Node *ans = ob.divide(N, head);
        printList(ans); 
    }
    return 0;
}
  // } Driver Code Ends

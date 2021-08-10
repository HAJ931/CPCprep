#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <stack>
using namespace std;
/* Link list Node */
struct Node {
  int data;
  struct Node *next;
  Node(int x) {
    data = x;
    next = NULL;
  }
};




 // } Driver Code Ends
/*
struct Node {
  int data;
  struct Node *next;
  Node(int x) {
    data = x;
    next = NULL;
  }
};
*/

class Solution{
    Node* findMiddle(Node* head){
        Node* fastPtr = head;
        Node* slowPtr = head;
        while(fastPtr && fastPtr->next){
            fastPtr = fastPtr->next->next;
            slowPtr = slowPtr->next;
        }
        return slowPtr;
    }
  public:
    //Function to check whether the list is palindrome.
    bool isPalindrome(Node *head)
    {
        //Your code here
        if(!head || !head->next)
            return true;
        Node* middle = findMiddle(head);
        Node* prev = NULL;
        Node* curr = middle;
        while(curr){
            Node* temp = curr->next;
            curr->next = prev;
            prev = curr;
            curr = temp;
        }
        while(head && prev){
            if(head->data != prev->data)
                return false;
            head = head->next;
            prev = prev->next;
        }
        return true;
    }
};



// { Driver Code Starts.
/* Driver program to test above function*/
int main()
{
  int T,i,n,l,firstdata;
    cin>>T;
    while(T--)
    {
        
        struct Node *head = NULL,  *tail = NULL;
        cin>>n;
        // taking first data of LL
        cin>>firstdata;
        head = new Node(firstdata);
        tail = head;
        // taking remaining data of LL
        for(i=1;i<n;i++)
        {
            cin>>l;
            tail->next = new Node(l);
            tail = tail->next;
        }
    Solution obj;
   	cout<<obj.isPalindrome(head)<<endl;
    }
    return 0;
}

  // } Driver Code Ends

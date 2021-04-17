#include<bits/stdc++.h>
using namespace std;

struct Node
{
	char data;
	struct Node *next;
	
	Node(int x){
	    data = x;
	    next = NULL;
	}
	
};

void printlist(Node *head)
{
	if (head==NULL)return;
	while (head != NULL)
	{
		cout << head->data << " ";
		head = head->next;
	}
	cout << endl;
}

void append(struct Node** headRef, char data)
{
	struct Node* new_node = new Node(data);
	struct Node *last = *headRef;

	if (*headRef == NULL)
	{
	    *headRef = new_node;
	    return;
	}
	while (last->next != NULL)
		last = last->next;
	last->next = new_node;
	return;
}

// task is to complete this function
struct Node* arrange(Node *head);

int main()
{
    int T;
    cin>>T;
    while(T--){
        int n;
        char tmp;
        struct Node *head = NULL;
        cin>>n;
        while(n--){
            cin>>tmp;
            append(&head, tmp);
        }
        head = arrange(head);
        printlist(head);
    }
	return 0;
}

// } Driver Code Ends


/*
Structure of the node of the linked list is as
struct Node
{
	char data;
	struct Node *next;
	
	Node(int x){
	    data = x;
	    next = NULL;
	}
	
};
*/
// task is to complete this function
// function should return head to the list after making 
// necessary arrangements
struct Node* arrange(Node *head)
{
   //Code here
   struct Node* vowelsBegin = NULL;
   struct Node* vowelsEnd = NULL;
   struct Node* consBegin = NULL;
   struct Node* consEnd = NULL;
   struct Node* curr = head;
   while(curr){
       if(toupper(curr->data) == 'A' || toupper(curr->data) == 'E' || 
       toupper(curr->data) == 'I' || toupper(curr->data) == 'O' || toupper(curr->data) == 'U'){
           if(!vowelsBegin){
               vowelsBegin = curr;
               vowelsEnd = vowelsBegin;
           }
           else{
               vowelsEnd->next = curr;
               vowelsEnd = vowelsEnd->next;
           }
       }
       else{
           if(!consBegin){
               consBegin = curr;
               consEnd = consBegin;
           }
           else{
               consEnd->next = curr;
               consEnd = consEnd->next;
           }
       }
       curr = curr->next;
   }
   if(!vowelsBegin || !consBegin)
        return head;
    vowelsEnd->next = consBegin;
    consEnd->next = NULL;
    return vowelsBegin;
}

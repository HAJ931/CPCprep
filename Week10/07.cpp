#include <bits/stdc++.h>
using namespace std;

class Stack {
    struct Node {
        int data;
        Node* next;
        Node* prev;
        Node(int num) {
            this->data = num;
        }
    };
    Node* head = NULL;
    Node* mid = NULL;
    int sz = 0;
    public:
    void push(int data) {
        Node* newNode = new Node(data);
        if(!head){
            head = newNode;
            mid = head;
        }
        else{
            newNode->next = head;
            head->prev = newNode;
            head = newNode;
            if(sz % 2 == 0)
                mid = mid->prev;
        }
        sz++;
    }
    int pop() {
        int val = -1;
        if(sz){
            val = head->data;
            if(sz == 1){
                head = NULL;
                mid = NULL;
            }
            else if(sz == 2){
                mid->prev = NULL;
                mid = head;
                head->next = NULL;
            }
            else if(sz % 2){
                mid = mid->next;
                Node* temp = head;
                head = head->next;
                head->prev = NULL;
                temp->next = NULL;
                free(temp);
            }
            else {
                Node* temp = head;
                head = head->next;
                head->prev = NULL;
                temp->next = NULL;
                free(temp);
            }
            sz--;
        }
        return val;
    }
    int findMiddle(){
        if(sz)
            return mid->data;
        return -1;
    }
    void deleteMiddle(){
        if(sz){
            if(sz == 1){
                head = NULL;
                mid = head;
            }
            else {
                mid->prev->next = mid->next;
                if(mid->next)
                    mid->next->prev = mid->prev;
                if(sz % 2){
                    mid = mid->next;
                }
                else {
                    mid = mid->prev;
                }
            }
            sz--;
        }
    }
    int peek() {
        if(sz)
            return head->data;
        return -1;
    }
};

int main() {
	Stack st;
	st.push(11);
    st.push(22);
    st.push(33);
    st.push(44);
    st.push(55);
    st.push(66);
    st.push(77);
    st.push(88);
    st.push(99);
    cout <<"Popped : "<< st.pop() << endl;
    cout <<"Popped : "<< st.pop() << endl;
    cout <<"Middle Element : "<< st.findMiddle() << endl;
    st.deleteMiddle();
    cout <<"New Middle Element : "<< st.findMiddle() << endl;
    return 0;
}

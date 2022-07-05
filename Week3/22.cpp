#include <bits/stdc++.h>

using namespace std;

class Node {
  public: 
  int val;
  Node* next;
  Node(int data) {
      this->val = data;
      this->next = NULL;
  }
  Node *addNode(Node* head, int val){
      Node* newNode = new Node(val);
      newNode->next = head;
      return newNode;
  }
  Node* makeList(Node* head, int n){
      for(int i = 0; i < n; ++i){
        int dat;
        cin >> dat;
        head = addNode(head, dat);
    }
    return head;
  }
};

class sortFunc {
    private:
        Node* splitList(Node* head) {
            Node* temp = NULL;
            Node* slow = head;
            Node* fast = head;
            while(fast && fast->next){
                temp = slow;
                slow = slow->next;
                fast = fast->next->next;
            }
            temp->next = NULL;
            return slow;
        }
        Node* merge(Node* head1, Node* head2, bool inc=true){
            if(!head1)
                return head2;
            if(!head2)
                return head1;
            Node* head;
            if(inc){
                if(head1->val <= head2->val){
                    head = head1;
                    head1->next = merge(head1->next, head2);
                }
                else {
                    head = head2;
                    head2->next = merge(head1, head2->next);
                }
            }
            else {
                if(head1->val >= head2->val){
                    head = head1;
                    head1->next = merge(head1->next, head2);
                }
                else {
                    head = head2;
                    head2->next = merge(head1, head2->next);
                }
            }
            return head;
        }
    public:
    Node* mergeSort(Node* head, bool inc=true){
        if(!head || !head->next)
            return head;
        Node* second = splitList(head);
        head = mergeSort(head, inc);
        second = mergeSort(second, inc);
        return merge(head, second, inc);
    }
};

vector<int> tripletSum(Node* head1, Node* head2, Node* head3, int target){
    while(head1){
        Node* ptr1 = head2;
        Node* ptr2 = head3;
        while(ptr1 && ptr2){
            if(head1->val + head2->val + head3->val == target)
                return {head1->val, head2->val, head3->val};
            else if(head1->val + head2->val + head3->val > target){
                ptr2 = ptr2->next;
            }
            else ptr1 = ptr1->next;
        }
        head1 = head1->next;
    }
    return {};
}

int main() {
    int n, target;
    cin >> n >> target;
    Node* head1 = NULL, *head2 = NULL, *head3 = NULL;
    head1 = head1->makeList(head1, n);
    head2 = head2->makeList(head2, n);
    head3 = head3->makeList(head3, n);
    sortFunc Sort;
    head2 = Sort.mergeSort(head2);
    head3 = Sort.mergeSort(head3, false);
    vector<int> ans = tripletSum(head1, head2, head3, target);
    for(auto x: ans){
        cout << x << "\n";
    }
    if(!ans.size())
        cout << "No such triplet!\n";
    
}

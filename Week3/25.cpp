/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
private:
    ListNode* merge(ListNode* h1, ListNode* h2, bool first=true){
        if(!h1)
            return h2;
        if(!h2)
            return h1;
        ListNode* head;
        if(first){
            head = h1;
            h1->next = merge(h1->next, h2, !first);
        }
        else {
            head = h2;
            h2->next = merge(h1, h2->next, !first);
        }
        return head;
    }
    ListNode* reverseList(ListNode* head){
        ListNode* prev = NULL, *curr = head;
        while(curr){
            ListNode* nex = NULL;
            nex = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nex;
        }
        return prev;
    }
public:
    void reorderList(ListNode* head) {
        //Split list
        if(!head || !head->next || !head->next->next)
            return;
        ListNode* temp = NULL;
        ListNode* slow = head;
        ListNode* fast = head;
        while(fast && fast->next){
            temp = slow;
            slow = slow->next;
            fast = fast->next->next;
        }
        temp->next = NULL;
        slow = reverseList(slow);
        merge(head, slow);
    }
};

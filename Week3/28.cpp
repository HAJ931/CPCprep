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
    ListNode* merge(ListNode* h1, ListNode* h2) {
        if(!h1)
            return h2;
        if(!h2)
            return h1;
        ListNode* head;
        if(h1->val <= h2->val){
            head = h1;
            h1->next = merge(h1->next, h2);
        }
        else {
            head = h2;
            h2->next = merge(h1, h2->next);
        }
        return head;
    }
public:
    ListNode* sortList(ListNode* head) {
        if(!head || !head->next)
            return head;
        ListNode* temp = NULL;
        ListNode* slow = head;
        ListNode* fast = head;
        while(fast && fast->next){
            temp = slow;
            slow = slow->next;
            fast = fast->next->next;
        }
        temp->next = NULL;
        head = sortList(head);
        slow = sortList(slow);
        return merge(head, slow);
    }
};

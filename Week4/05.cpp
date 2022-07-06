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
public:
    ListNode* swapNodes(ListNode* head, int k) {
        if(!head || !head->next)
            return head;
        ListNode* sentinel = new ListNode(0, head);
        ListNode *slow, *fast = sentinel, *first = NULL;
        ListNode* prev1 = sentinel, *prev2 = sentinel;
        while(fast && k--){
            prev1 = fast;
            fast = fast->next;
        }
        cout << fast->val;
        if(k > 0 || !fast) return head;
        slow = sentinel;
        first = fast;
        while(fast){
            prev2 = slow;
            slow = slow->next;
            fast = fast->next;
        }
        prev1->next = slow;
        prev2->next = first;
        ListNode* temp = first->next;
        first->next = slow->next;
        slow->next = temp;
        return sentinel->next;
    }
};

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
        ListNode *slow, *fast = head, *first = NULL;
        while(fast && --k){
            fast = fast->next;
        }
        if(k || !fast) return head;
        slow = head;
        first = fast;
        fast = fast->next;
        while(fast){
            slow = slow->next;
            fast = fast->next;
        }
        swap(slow->val, first->val);
        return head;
    }
};

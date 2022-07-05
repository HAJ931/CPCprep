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
    ListNode* swapPairsUtil(ListNode* first, ListNode* second){
        if(!second)
            return first;
        ListNode* temp = second->next;
        second->next = first;
        first->next = temp ? swapPairsUtil(temp, temp->next): temp;
        return second;
    }
public:
    ListNode* swapPairs(ListNode* head) {
        if(!head || !head->next)
            return head;
        return swapPairsUtil(head, head->next);
    }
};

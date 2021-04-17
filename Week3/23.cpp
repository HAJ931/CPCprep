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
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* ref = head;
        ListNode *nex = NULL;
        ListNode *nexToNex = NULL;
        while(ref){
            nex = ref->next;
            while(nex){
                if(nex->val != ref->val)
                    break;
                nexToNex = nex->next;
                nex->next = NULL;
                nex = nexToNex;
            }
            ref->next = nex;
            ref = ref->next;
        }
        return head;
    }
};

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
        auto dummy = new ListNode(0, head);
        for(auto cur = dummy; cur; ) {
            if(cur->next && cur->next->next && cur->next->val == cur->next->next->val) {
                auto T = cur->next->next;
                while(T) {
                    if(T->next && T->val == T->next->val) T = T->next;
                    else break;
                }
                cur->next = T->next;
            } else {
                cur = cur->next;
            }
        }
        return dummy->next;
    }
};
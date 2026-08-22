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
        for(auto cur = dummy; cur->next;) {
            auto F = cur->next;
            auto L = cur->next->next;
            while(L && F->val == L->val) L = L->next;
            if(F->next == L) cur = cur->next;
            else cur->next = L;
        }
        return dummy->next;
    }
};
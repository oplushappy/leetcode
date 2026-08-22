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
    ListNode* partition(ListNode* head, int x) {
        auto dummy = new ListNode(0, head);
        auto L = dummy;
        while(L) {
            if(L->next && L->next->val < x) L = L->next;
            else break;
        }
        ListNode* cur = L->next;
        while(cur) {
            if(cur->next && cur->next->val < x) {
                auto l = cur->next;
                auto nxt2 = cur->next->next;
                auto G = L->next;
                L->next = l;
                l->next = G;
                cur->next = nxt2;
                L = L->next;
            } else {
                cur = cur->next;
            }
        }
        return dummy->next;
    }
};
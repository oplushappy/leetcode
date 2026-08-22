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
    ListNode* swapPairs(ListNode* head) {
        auto dummy = new ListNode(0, head);
        auto cur = dummy->next; 
        auto prev = dummy;
        while(cur && cur->next) {
            auto nxt = cur->next;
            auto nxt2 = cur->next->next;
            nxt->next = cur;
            cur->next = nxt2;
            prev->next = nxt;

            prev = cur;
            cur = nxt2;
        }
        return dummy->next;
    }
};
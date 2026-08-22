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
        auto cur = dummy; 
        while(cur->next && cur->next->next) {
            auto nxt1 = cur->next;
            auto nxt2 = cur->next->next;
            auto nxt3 = cur->next->next->next;
            cur->next = nxt2;
            nxt2->next = nxt1;
            nxt1->next = nxt3;
            cur = nxt1;
        }
        return dummy->next;
    }
};
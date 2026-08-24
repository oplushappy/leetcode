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
    void reverseAfterK(ListNode* cur, int k) {
        auto T = cur->next;
        while(--k) {
            auto F = cur->next;
            auto N = T->next;
            auto NN = N->next;
            cur->next = N;
            N->next = F;
            T->next = NN;
        }
    }
public:
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        auto dummy = new ListNode(0, head);
        auto cur = dummy;
        for(int i = 1; i < left; i++) cur = cur->next;
        reverseAfterK(cur, right - left + 1);
        return dummy->next;
    }
};
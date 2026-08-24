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
    ListNode* reverseAfterK(ListNode* cur, int k) {
        auto T = cur->next;
        while(--k) {
            auto F = cur->next;
            auto N = T->next;
            auto NN = N->next;
            cur->next = N;
            N->next = F;
            T->next = NN;
        }
        return T;
    }
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        auto dummy = new ListNode(0, head);
        int len = 0;
        for(auto cur = dummy->next; cur; cur = cur->next) len++;
        int times = len / k;
        auto cur = dummy;
        while(times--) {
            cur = reverseAfterK(cur, k);
        }
        return dummy->next;
    }
};
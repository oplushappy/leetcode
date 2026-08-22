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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* dummy = new ListNode(0, head);
        int len = 0;
        for(auto cur = dummy->next; cur; cur = cur->next) len++;
        int step = len - n;
        auto cur = dummy;
        while(step--) cur = cur->next;
        cur->next = cur->next->next;
        return dummy->next;
    }
};
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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if(left == right) return head;
        auto dummy = new ListNode(0, head);
        ListNode* leftN, * rightN, *tmpD;
        int n = 0;
        auto cur = dummy;
        while(cur) {
            if(n == left - 1) {
                tmpD = cur;
                leftN = cur->next;
                n++;
                break;
            }
            cur = cur->next;
            n++;
        }
        for(auto cur = leftN; cur; cur = cur->next, n++) {
            if(n == right) {
                rightN = cur;
                break;
            }
        }
        ListNode* prev = nullptr;
        cur = leftN;
        ListNode* nxt;
        while(cur) {
            nxt = cur->next;
            cur->next = prev;
            prev = cur;
            cur = nxt;
            if(prev == rightN) break;
        }
        tmpD->next = rightN;
        leftN->next = nxt;
        return dummy->next;
    }
};
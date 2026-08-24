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
    void reorderList(ListNode* head) {
        if(!head || !head->next) return;

        auto slow = head;
        auto fast = head;
        while(fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }

        auto second = slow->next;
        slow->next = nullptr;
        ListNode *prev = nullptr;
        while(second) {
            auto nxt = second->next;
            second->next = prev;
            prev = second; // notice
            second = nxt;
        }

        auto l1 = head;
        auto l2 = prev;
        while(l2) {
            auto nxt1 = l1->next;
            auto nxt2 = l2->next;
            l1->next = l2;
            l2->next = nxt1;
            l1 = nxt1;
            l2 = nxt2;
        }
        
    }
};
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
    ListNode* sortList(ListNode* head) {
        vector<pair<int, ListNode*>> v;
        for(auto cur = head; cur; cur = cur->next) v.push_back({cur->val, cur});
        sort(v.begin(), v.end());
        auto dummy = new ListNode(0,0);
        auto cur = dummy;
        for(int i = 0; i < v.size(); i++) {
            cur->next = v[i].second;
            cur = cur->next;
        }
        cur->next = nullptr;
        return dummy->next;
    }
};
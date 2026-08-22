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
    bool isPalindrome(ListNode* head) {
        auto dummy = new ListNode(0, head);
        vector<int> v;
        for(auto cur = dummy->next; cur; cur = cur->next) v.push_back(cur->val);
        auto v1 = v;
        reverse(v1.begin(), v1.end());
        return v == v1;

    }
};
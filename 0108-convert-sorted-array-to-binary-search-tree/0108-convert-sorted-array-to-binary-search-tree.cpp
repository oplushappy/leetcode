/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        auto build = [&](auto &self, int l, int r) -> TreeNode* {
            if(l > r) return nullptr;
            int mid = l + (r - l) / 2;
            TreeNode* node = new TreeNode(nums[mid]);
            node->left = self(self, l, mid - 1);
            node->right = self(self, mid + 1, r);
            return node;
        };
        return build(build, 0, nums.size() - 1);
    }
};
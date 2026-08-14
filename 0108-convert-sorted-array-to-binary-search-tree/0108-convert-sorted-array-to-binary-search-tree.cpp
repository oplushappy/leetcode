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
        int n = nums.size();
        vector<bool> visited(n, false);
        auto build = [&](auto &self, int l, int r, TreeNode* cur) {
            if(l < 0 || r < 0 || l >= n || r >= n) return;
            if(l > r) return;
            int mid = l + (r - l) / 2;
            if(!(mid >= 0 && mid < n)) return;
            if(visited[mid]) return;
            visited[mid] = true;
            TreeNode* node = new TreeNode(nums[mid]);
            if(nums[mid] > cur->val) cur->right = node;
            else cur->left = node;
            self(self, l, mid-1, node);
            self(self, mid + 1, r, node);
        };
        int m = nums.size()/ 2;
        TreeNode* root = new TreeNode(nums[m]);
        build(build, 0, m - 1, root);
        build(build, m + 1, nums.size() - 1, root);
        return root;
    }
};
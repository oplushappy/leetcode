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
    int goodNodes(TreeNode* root) {
        return dfs(root, root->val);
    }
    int dfs(TreeNode* node, int maximum) {
        if(!node) {
            return 0;
        }
        // preorder, first solve the root (node itself)
        int res = (node->val >= maximum) ? 1 : 0;
        maximum = max(maximum, node->val);
        // then to solve left child and right child
        res += dfs(node->left, maximum);
        res += dfs(node->right, maximum);
        return res;
    }
};
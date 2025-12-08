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
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if(root == nullptr && subRoot == nullptr) return true;
        if(root && subRoot == nullptr) return true;
        if(root == nullptr && subRoot) return false;

        if(isSameTree(root, subRoot)) {
            return true;
        }
        
        return isSubtree(root->left, subRoot) || isSubtree(root->right, subRoot);
    }

    bool isSameTree(TreeNode* s, TreeNode* t) {
        if(s == nullptr && t == nullptr) {
            return true;
        }

        if(s && t && s->val == t->val) {
            return isSameTree(s->left, t->left) && isSameTree(s->right, t->right);
        }

        return false;
    }
};
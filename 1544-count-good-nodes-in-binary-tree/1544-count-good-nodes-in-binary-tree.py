# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def goodNodes(self, root: TreeNode) -> int:
        ans = 0
        def dfs(root, maxNum):
            if root is None:
                return

            if root.val >= maxNum:
                maxNum = root.val
                nonlocal ans
                ans += 1
            
            dfs(root.left, maxNum)
            dfs(root.right, maxNum)

        dfs(root, root.val)
        return ans

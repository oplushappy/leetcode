# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def isUnivalTree(self, root: Optional[TreeNode]) -> bool:
        value = root.val
        def dfs(root):
            if root is None:
                return True
            if root.val != value:
                return False
            if not dfs(root.left): return False
            if not dfs(root.right): return False
            return True
        
        return dfs(root)